#include "Complex.h"
#include <cmath>
#include <iostream>

using namespace std;

Complex::Complex() : real(0), imag(0) {
}

Complex::Complex(double r, double i) : real(r), imag(i) {
}

void Complex::Print() const {
    if (imag < 0) {
        cout << real << " - " << -imag << "i\n";
    } else {
        cout << real << " + " << abs(imag) << "i\n";
    }
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(double scalar) const {
    return Complex(real * scalar, imag * scalar);
}

Complex operator*(double scalar, const Complex& number) {
    return number * scalar;
}

Complex Complex::operator*(const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

Complex::operator double() const {
    return hypot(real, imag);
}
