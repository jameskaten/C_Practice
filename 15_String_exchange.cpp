#include <iostream>
#include <string>

int main() {
    std::string k = "Korea";
    std::string c = "China";
    std::string tmp;

    std::cout << "Original ==> k = " << k << ", c = " << c << std::endl;

    // Manual swap using std::string's assignment operator
    // This is safe - no buffer size concerns like with strcpy
    tmp = k;  // Copy k to tmp
    k = c;    // Copy c to k
    c = tmp;  // Copy tmp (original k) to c

    std::cout << "After ==> k = " << k << ", c = " << c << std::endl;
    
    return 0;
}