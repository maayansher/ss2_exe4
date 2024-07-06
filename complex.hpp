//Email: maayan1sher@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;
class Complex
{
private:
    double re;
    double im;

public:
    Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}

    double get_re() const
    {
        return re;
    }

    double get_im() const
    {
        return im;
    }

    void set_re(double r)
    {
        this->re = r;
    }

    void set_im(double im)
    {
        this->im = im;
    }
    bool operator==(const Complex &other) const
    {
        return re == other.re && im == other.im;
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Complex &other) const
    {
        return magnitude() < other.magnitude();
    }

    bool operator>(const Complex &other) const
    {
        return magnitude() > other.magnitude();
    }

    double magnitude() const
    {
        return sqrt(re * re + im * im);
    }

    friend ostream &operator<<(ostream &os, const Complex &complex)
    {
        os << complex.to_string();
        return os;
    }

    string to_string() const
    {
        ostringstream os;
        if (re == 0 && im == 0)
        {
            os << "0";
        }
        else if (re == 0)
        {
            os << im << "i";
        }
        else if (im == 0)
        {
            os << re;
        }
        else
        {
            os << re << (im >= 0 ? " + " : " - ") << abs(im) << "i";
        }
        return os.str();
    }
};

#endif