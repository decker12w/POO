#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Sobrecarga do operador +
    Complex operator+(const Complex &rhs)
    {
        return Complex(real + rhs.real, imag + rhs.imag);
    }

    // Sobrecarga do operador -
    Complex operator-(const Complex &rhs)
    {
        return Complex(real - rhs.real, imag - rhs.imag);
    }

    // Sobrecarga do operador *
    Complex operator*(const Complex &rhs)
    {
        return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
    }

    // Sobrecarga do operador /
    Complex operator/(const Complex &rhs)
    {
        double denominator = rhs.real * rhs.real + rhs.imag * rhs.imag;
        return Complex((real * rhs.real + imag * rhs.imag) / denominator, (imag * rhs.real - real * rhs.imag) / denominator);
    }

    // Sobrecarga do operador ==
    bool operator==(const Complex &rhs)
    {
        return real == rhs.real && imag == rhs.imag;
    }

    // Sobrecarga do operador =
    Complex &operator=(const Complex &rhs)
    {
        if (this != &rhs)
        {
            real = rhs.real;
            imag = rhs.imag;
        }
        return *this;
    }

    // Sobrecarga do operador --
    Complex &operator--()
    {
        --real;
        --imag;
        return *this;
    }

    // Sobrecarga do operador ++
    Complex &operator++()
    {
        ++real;
        ++imag;
        return *this;
    }

    // Sobrecarga do operador <<
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real;
        if (c.imag < 0)
            os << c.imag << 'i';
        else
            os << '+' << c.imag << 'i';
        return os;
    }

private:
    double real, imag;
};
