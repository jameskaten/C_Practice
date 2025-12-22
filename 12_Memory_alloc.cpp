// Include the iostream library for input/output operations (cout, cin)
#include <iostream>
// Include cstdlib for standard library functions (though not strictly needed here)
#include <cstdlib>

// Main function - entry point of the program
int main() {
    // Variable declarations
    int n, i;        // n: number of integers to store, i: loop counter
    int* p;          // p: pointer to dynamically allocated integer array
    
    // Prompt user to enter the total number of integers
    std::cout << "Total numbers: ";
    // Read the number of integers from user input
    std::cin >> n;
    
    // Dynamically allocate memory for an array of n integers
    // 'new int[n]' allocates memory on the heap and returns a pointer to the first element
    // This allows us to create arrays whose size is determined at runtime
    p = new int[n];
    
    // Check if memory allocation was successful
    // If new fails, it throws an exception (in modern C++), but checking nullptr is good practice
    // In older C++ or with nothrow, it could return nullptr
    if (p == nullptr) {
        std::cout << "Fail" << std::endl;
        return 1;  // Return error code 1 to indicate failure
    }
    
    // Prompt user that we're about to collect n integers
    std::cout << "[" << n << "] number of int: " << std::endl;
    
    // Loop to read n integers from the user
    for (i = 0; i < n; i++) {
        // Display which integer we're currently asking for (0-indexed)
        std::cout << "[" << i << "] integer: ";
        // Read the integer and store it in the array at index i
        // p[i] is equivalent to *(p + i) - array indexing using pointer arithmetic
        std::cin >> p[i];
    }
    
    // Print a header before displaying all the stored integers
    std::cout << "\n [" << n << "] integer prin" << std::endl;
    
    // Loop to print all n integers that were stored
    for (i = 0; i < n; i++) {
        // Display the index and the corresponding value
        // Format: [index] ==> value
        std::cout << "[" << i << "] ==> " << p[i] << std::endl;
    }
    
    // Deallocate the dynamically allocated memory
    // 'delete[]' is used for arrays allocated with 'new[]'
    // This is crucial to prevent memory leaks - every 'new[]' must have a corresponding 'delete[]'
    // Using 'delete' instead of 'delete[]' would be undefined behavior
    delete[] p;
    
    // Return 0 to indicate successful program execution
    return 0;
}