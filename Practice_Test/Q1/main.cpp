#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
    double r1, i1, r2, i2, scalar;

    cout << "Enter the real and imaginary parts of Z1: ";
    cin >> r1 >> i1;

    cout << "Enter the real and imaginary parts of Z2: ";
    cin >> r2 >> i2;

    cout << "Enter the scalar: ";
    cin >> scalar;

    Complex z1(r1, i1);
    Complex z2(r2, i2);

    cout << "\nZ1 = ";
    z1.Print();

    cout << "Z2 = ";
    z2.Print();

    cout << "Z1 + Z2 = ";
    (z1 + z2).Print();

    cout << "Z1 - Z2 = ";
    (z1 - z2).Print();

    cout << "Z1 * scalar = ";
    (z1 * scalar).Print();

    cout << "Z1 * Z2 = ";
    (z1 * z2).Print();

    double magnitude = z1;
    cout << "Magnitude of Z1 = " << magnitude << '\n';

    return 0;
}
