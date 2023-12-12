#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex& other) {
        double newReal = real + other.real;
        double newimag = imag + other.imag;
        return Complex(newReal, newimag);
    }
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }
    void display() {
        if (imag < 0)
            cout << real << " - " << -imag << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.0, 1.5);
    Complex c2(1.5, 4.5);
    Complex sum = c1 + c2;
    Complex c3(0, 0);
    c3 = c1 + c2;

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "c1 + c2 = ";
    sum.display();
    cout << "c3 = ";
    c3.display();

    return 0;
}
