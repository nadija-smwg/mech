#include "Complex.h"

#include <iostream>

int main() {
    double real1, imaginary1, real2, imaginary2, scalar;

    std::cout << "Enter the real and imaginary parts of Z1: ";
    if (!(std::cin >> real1 >> imaginary1)) {
        std::cerr << "Enter two numeric components.\n";
        return 1;
    }

    std::cout << "Enter the real and imaginary parts of Z2: ";
    if (!(std::cin >> real2 >> imaginary2)) {
        std::cerr << "Enter two numeric components.\n";
        return 1;
    }

    std::cout << "Enter a scalar: ";
    if (!(std::cin >> scalar)) {
        std::cerr << "Enter a numeric scalar.\n";
        return 1;
    }

    const Complex z1(real1, imaginary1);
    const Complex z2(real2, imaginary2);

    std::cout << "\nZ1 = ";
    z1.Print();
    std::cout << "Z2 = ";
    z2.Print();
    std::cout << "Z1 + Z2 = ";
    (z1 + z2).Print();
    std::cout << "Z1 - Z2 = ";
    (z1 - z2).Print();
    std::cout << "Z1 * scalar = ";
    (z1 * scalar).Print();
    std::cout << "scalar * Z1 = ";
    (scalar * z1).Print();
    std::cout << "Z1 * Z2 = ";
    (z1 * z2).Print();

    double magnitude = z1;
    std::cout << "Magnitude of Z1 = " << magnitude << '\n';
}
