#include <iostream>
#include <cstring>

// In C++, struct is a class with public members by default
// No need for typedef - we can use Person directly
struct Person {
    char* name;
};

int main() {
    Person original;
    // Use new instead of malloc - C++ style memory allocation
    original.name = new char[50];
    if (original.name == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }
    // Use strcpy from <cstring> (C++ version of string.h)
    std::strcpy(original.name, "Allice");

    // Shallow copy - both pointers point to the same memory location
    // Changing one will affect the other
    Person shallowCopy;
    shallowCopy.name = original.name;  // Just copying the pointer, not the data

    // Deep copy - allocate new memory and copy the actual string data
    // Changing one will NOT affect the other
    Person deepCopy;
    deepCopy.name = new char[50];
    if (deepCopy.name == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        delete[] original.name;  // Clean up before exiting
        return 1;
    }
    std::strcpy(deepCopy.name, original.name);  // Copy the actual string data

    // Display initial values
    std::cout << "Original name: " << original.name << std::endl;
    std::cout << "Shallow copy name: " << shallowCopy.name << std::endl;
    std::cout << "Deep copy name: " << deepCopy.name << std::endl;

    // Modify original name
    std::strcpy(original.name, "Bob");
    
    // Show result - shallow copy will change, deep copy won't
    std::cout << "\nAfter Modification" << std::endl;
    std::cout << "Original name: " << original.name << std::endl;
    std::cout << "Shallow copy name: " << shallowCopy.name << std::endl;
    std::cout << "Deep copy name: " << deepCopy.name << std::endl;

    // Clean up memory - use delete[] for arrays allocated with new[]
    // Note: Only delete original.name and deepCopy.name
    // Don't delete shallowCopy.name - it points to the same memory as original.name
    delete[] original.name;
    delete[] deepCopy.name;
    // shallowCopy.name is now a dangling pointer, but that's okay since we're exiting

    return 0;
}