#include <iostream>
#include <string>

int main() {
    // Use std::string instead of C-style char arrays
    // std::string automatically manages memory and is safer
    std::string k = "Korea";
    std::string c = "China";
    std::string tmp;

    // Display original values using std::cout
    std::cout << "Original ==> k = " << k << ", c = " << c << std::endl;

    // Swap the strings using std::string's assignment operator
    // This is much safer than strcpy - no buffer overflow risks
    tmp = k;  // Copy k to tmp
    k = c;    // Copy c to k
    c = tmp;  // Copy tmp (original k) to c

    // Display swapped values
    std::cout << "After ==> k = " << k << ", c = " << c << std::endl;

    return 0;
}