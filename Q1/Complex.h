#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
protected:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double realPart, double imaginaryPart);

    void Print() const;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(double scalar) const;
    Complex operator*(const Complex& other) const;
    operator double() const;
};

Complex operator*(double scalar, const Complex& number);

#endif
