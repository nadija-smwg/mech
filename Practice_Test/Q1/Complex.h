#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
protected:
    double real;
    double imag;

public:
    Complex();
    Complex(double r, double i);

    void Print() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(double scalar) const;
    Complex operator*(const Complex& other) const;

    operator double() const;
};

Complex operator*(double scalar, const Complex& number);

#endif
