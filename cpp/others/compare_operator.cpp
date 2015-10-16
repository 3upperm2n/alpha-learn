#include <iostream>


int main() {
    int a = 2;
    int b = -1; 

    int c = 0;

    c = c + (a > 0);
    std::cout << "c = " << c << std::endl;

    c = c + (b > 0);
    std::cout << "c = " << c << std::endl;

    c = c + (a > 0);
    std::cout << "c = " << c << std::endl;

    return 0;    
}
