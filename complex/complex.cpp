nclude <iostream>
#include <cmath>

using namespace std;

class Complex {
public:
    Complex() {
    }

    Complex(const double real, const double imaginary) {
        _real = real;
        _imaginary = imaginary;
    }

    Complex(const Complex& copied) {
        _real = copied._real;
        _imaginary = copied._imaginary;
    }

    Complex& operator=(const Complex& copied) {
     	 _real = copied._real;
        _imaginary = copied._imaginary;
        return (*this);
    }

    ~Complex() {

    }

    bool operator!=(const Complex& other) const {
        if (_real != other._real || _imaginary != other._imaginary) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator==(const Complex& other) const {
        if (_real != other._real && _imaginary != other._imaginary) {
            return false;
        }
        else {
            return true;
        }
    }

    Complex operator-() const {
        Complex a (*this);
        a._real = -a._real;
        a._imaginary = -a._imaginary;
        return a;
    }

    Complex operator+(const Complex& other) const {
        Complex a (*this);
        a._real += other._real;
        a._imaginary += other._imaginary;
        return a;
    }

    Complex operator-(const Complex& other) const {
        Complex a (*this);
        a._real -= other._real;
        a._imaginary -= other._imaginary;
        return a;
    }

    Complex operator*(const Complex& other) const {
        Complex a (*this);
        Complex b (*this);
        a._real = b._real * other._real - b._imaginary * other._imaginary;
        a._imaginary *= b._imaginary * other._real + b._real * other._imaginary;
        return a;
    }

    Complex operator/(const Complex& other) const {
        Complex a (*this);
        Complex b (*this);
        a._real = (a.module() / other.module()) * cos(b.argument() - other.argument());
        a._imaginary = (a.module() / other.module()) * sin(b.argument() - other.argument());
        return a;
    }

    double module() const {
        return (sqrt(_real * _real + _imaginary * _imaginary));
    }

    double argument() const {
        return asin(_real / (module()));
    }

    Complex Conjugate() const {
        Complex a(*this);
        a._imaginary = - a._imaginary;
        return a;
    }

private:
    double _real, _imaginary;
};

int main() {
    int errors = 0, tests = 0;
    Complex a;

    Complex b(1, 2);
    Complex c(b);
    ++tests;
    if (b != c) {
        cout << "Error: b != c" << endl;
        ++errors;
    }

    Complex d(2, 3);
    ++tests;
    if (b == d) {
        cout << "Error: b == d" << endl;
        ++errors;
    }
    Complex e = d;
    ++tests;
    if (d != e) {
        cout << "Error: d != e" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(3, 4).module() != 5) {
        cout << "Error: |3 + 4i| != 5" << endl;
        ++errors;
    }

    ++tests;
    if (fabs(Complex(3, 4).argument() - 0.6435011087) > 0.0000001) {
        cout << "Error: arg(3 + 4i) != " << endl;
        ++errors;
    }

    ++tests;
    if (- Complex(1, -3) != Complex(-1, 3)) {
        cout << "Error: - Complex(1, -3) != Complex(-1, 3)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(1, -3) + Complex(4, 2) != Complex(5, -1)) {
        cout << "Error: Complex(1, -3) + Complex(4, 2) != Complex(5, -1)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(1, -3) - Complex(4, 2) != Complex(-3, -5)) {
        cout << "Error: Complex(1, -3) - Complex(4, 2) != Complex(-3, -5)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(4, 3) * Complex(1, -2) != Complex(10, -5)) {
        cout << "Error: Complex(4, 3) * Complex(1, -2) != Complex(10, -5)" << endl;
        ++errors;
    }

    ++tests;
    if (Complex(4, 3) / Complex(1, 2) != Complex(2, -1)) {
        cout << "Error: Complex(4, 3) / Complex(1, 2) != Complex(2, -1)" << endl;
        ++errors;
    }

    cout << "Number of tests: " << tests << ", number of errors: " << errors << endl;


    return 0;
}