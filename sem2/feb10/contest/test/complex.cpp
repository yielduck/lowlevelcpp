#include <cmath>
namespace student
{
class Complex
{
    double x, y;
public:
    Complex(double re = 0., double im = 0.);
    double real() const;
    double imag() const;
    Complex &operator+=(Complex const &);
    Complex &operator-=(Complex const &);
    Complex &operator*=(Complex const &);
    Complex &operator/=(Complex const &);
};
double norm(Complex const &);
double  arg(Complex const &);
Complex operator+(Complex const &, Complex const &);
Complex operator-(Complex const &, Complex const &);
Complex operator*(Complex const &, Complex const &);
Complex operator/(Complex const &, Complex const &);    

#include "../solution/complex.h"
}

#include <iostream>
int main()
{
    auto const print = [](student::Complex const &c)
    {
        std::cout << c.real() << ' ' << c.imag() << std::endl;
    };
    
    student::Complex c0(1, 1), c1(-1, -2), c2(3, -1);
    std::cout << c1.real() << ' ' << c1.imag() << std::endl;
    std::cout << norm(c0) << ' ' << norm(c1) << ' ' << norm(c2) << std::endl;
    std::cout << arg(c1) << ' ' << arg(c2) << std::endl;
    
    print(c1);
    print(c1 + c2);
    print(c1 - c2);
    print(c1 * c2);
    print(c1 / c2);
    print(c0 += c1);
    print(c0 -= c1);
    print(c0 *= c1);
    print(c0 /= c1);
}
