#include "Complex.h"

#include <cmath>
#include <iostream>

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart) {}

void Complex::Print() const {
    std::cout << real << (imaginary < 0 ? " - " : " + ")
              << std::abs(imaginary) << "i\n";
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(double scalar) const {
    return Complex(real * scalar, imaginary * scalar);
}

Complex operator*(double scalar, const Complex& number) {
    return number * scalar;
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
                   real * other.imaginary + imaginary * other.real);
}

Complex::operator double() const {
    return std::hypot(real, imaginary);
}
