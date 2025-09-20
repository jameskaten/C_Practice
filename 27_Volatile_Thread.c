// 27_Volatile_Thread_mac.c
//
// Purpose:
//   macOS/POSIX rewrite of a Windows CreateThread/Sleep example that waits
//   for a "flag" set by a background thread after a delay.
//
// Why atomics (not just `volatile`):
//   - `volatile` only prevents certain compiler optimizations; it does NOT
//     provide inter-thread visibility or ordering guarantees.
//   - C11 atomics (`stdatomic.h`) provide well-defined synchronization.
//   - We use a release-store / acquire-load pair to guarantee that once the
//     main thread observes `flag == true`, it also observes all writes
//     that happened-before that store (none here besides the flag itself,
//     but this is the correct pattern).
//
// Mapping from Windows to POSIX:
//   - Windows: CreateThread / WaitForSingleObject / Sleep
//   - POSIX:   pthread_create / pthread_join / usleep (or nanosleep)
//
// Build (macOS):
//   cc -std=c11 -Wall -Wextra -O2 27_Volatile_Thread_mac.c -o 27_Volatile_Thread_mac -pthread
//
// Notes:
//   - For demo simplicity we poll the flag with a short sleep (10 ms).
//     In real systems, prefer condition variables, semaphores, or events
//     to avoid polling. Polling is acceptable here to mirror the original
//     Windows example.
//   - `usleep` takes microseconds; for more precise or portable timing,
//     consider `nanosleep`.
//   - On terminals, `printf` is typically line-buffered, so explicit
//     `fflush(stdout)` isn’t necessary for the prints shown here.

#include <stdio.h>        // printf, perror
#include <stdbool.h>      // bool
#include <stdatomic.h>    // atomic_bool, atomic_store_explicit, atomic_load_explicit
#include <pthread.h>      // pthread_create, pthread_join, pthread_t
#include <unistd.h>       // usleep

// Shared flag visible to both threads.
//  - atomic_bool ensures atomicity and memory ordering can be specified.
//  - Initialize to `false`, as the worker will set it to `true` after a delay.
static atomic_bool flag = false;

// Thread entry function (similar to a Windows LPTHREAD_START_ROUTINE).
// Returns NULL (POSIX convention). The `arg` is unused here.
static void* interrupt_handler(void* arg) {
    (void)arg;  // explicitly silence unused-parameter warning

    // Simulate an "interrupt" arriving after 2000 ms.
    // usleep takes microseconds: 2000 ms = 2,000,000 µs
    usleep(2000 * 1000);

    // Publish the "interrupt" by setting the flag to true.
    // memory_order_release guarantees:
    //  - All prior writes in this thread become visible to other threads
    //    that perform an acquire load of `flag` and see `true`.
    atomic_store_explicit(&flag, true, memory_order_release);

    printf("Interrupt triggered: flag set to true\n");

    return NULL;
}

int main(void) {
    pthread_t th;

    // Create the worker thread that will set the flag after a delay.
    // Returns 0 on success, nonzero on error.
    if (pthread_create(&th, NULL, interrupt_handler, NULL) != 0) {
        // If thread creation fails, print the system error and exit.
        perror("pthread_create");
        return 1;
    }

    printf("Main thread: waiting for flag\n");

    // Wait (poll) until the background thread sets the flag.
    // memory_order_acquire pairs with the worker's release-store, ensuring
    // that once we read `true`, we see everything that happened-before it
    // in the worker (again, just the flag here, but this is the correct pattern).
    while (!atomic_load_explicit(&flag, memory_order_acquire)) {
        // Sleep briefly to avoid hot spinning.
        // This mirrors the Windows example's Sleep(10).
        usleep(10 * 1000);  // 10 ms
    }

    printf("Main thread: flag detected!\n");

    // Join the worker thread to ensure it has finished.
    // (In more complex programs, this also serves as a synchronization point.)
    pthread_join(th, NULL);

    return 0;
}
