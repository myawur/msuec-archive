#include <iomanip>
#include <iostream>

using namespace std;

class Complex {
   public:
    double real = 0;
    double image = 0;

    Complex(double re = 0, double im = 0) {
        real = re;
        image = im;
    }

    Complex operator+(Complex& second) {
        Complex tmp(0, 0);
        tmp.real = real + second.real;
        tmp.image = image + second.image;
        return tmp;
    }

    Complex operator-(Complex& second) {
        Complex tmp(0, 0);
        tmp.real = real - second.real;
        tmp.image = image - second.image;
        return tmp;
    }

    Complex operator*(Complex& second) {
        Complex tmp(0, 0);
        tmp.real = real * second.real - image * second.image;
        tmp.image = real * second.image + second.real * image;
        return tmp;
    }

    Complex operator/(Complex& second) {
        Complex tmp(0, 0);
        double temp = second.real * second.real + second.image * second.image;

        if (temp == 0) {
            throw "Division by zero";
        }

        tmp.real = (real * second.real + image * second.image) / temp;
        tmp.image = (image * second.real - real * second.image) / temp;
        return tmp;
    }
};

int main() {
    double re, im;

    cin >> re >> im;
    Complex c1(re, im);
    cin >> re >> im;
    Complex c2(re, im);
    Complex c3;

    char action;
    cin >> action;

    switch (action) {
        case '+':
            c3 = c1 + c2;
            break;
        case '-':
            c3 = c1 - c2;
            break;
        case '*':
            c3 = c1 * c2;
            break;
        case '/':
            try {
                c3 = c1 / c2;
            } catch (char const* error_message) {
                cout << error_message << endl;
                return 0;
            }
            break;
    }

    cout << fixed << setprecision(4) << c3.real << "  " << c3.image << endl;

    return 0;
}
