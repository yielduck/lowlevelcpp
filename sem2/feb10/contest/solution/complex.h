Complex::Complex(double re, double im)
    : x(re)
    , y(im)
{}
double Complex::real() const {return x;}
double Complex::imag() const {return y;}

double  arg(Complex const &c) {return std::atan2(c.imag(), c.real());}
double norm(Complex const &c) {return c.real() * c.real() + c.imag() * c.imag();}

Complex &Complex::operator+=(Complex const &other)
{
    x += other.x;
    y += other.y;
    return *this;
}
Complex &Complex::operator-=(Complex const &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}
Complex &Complex::operator*=(Complex const &other)
{
    *this =
    {
        x * other.x - y * other.y,
        x * other.y + y * other.x,
    };
    return *this;
}
Complex &Complex::operator/=(Complex const &other)
{
    *this *= {other.x, -other.y};
    x /= norm(other);
    y /= norm(other);
    return *this;
}
Complex operator+(Complex const &a, Complex const &b) {Complex c = a; return c += b;}
Complex operator-(Complex const &a, Complex const &b) {Complex c = a; return c -= b;}
Complex operator*(Complex const &a, Complex const &b) {Complex c = a; return c *= b;}
Complex operator/(Complex const &a, Complex const &b) {Complex c = a; return c /= b;}
