#include <iostream>

using namespace std;

// Function to evaluate a polynomial of the form ax^3 + bx^2 + cx + d
double evaluatePolynomial(double a, double b, double c, double d, double x) {
    double result = 0;

    if (a != 0) {
        result += a * x * x * x;
        cout << "Evaluating cubic term: " << a << "x^3" << endl;
    }
    if (b != 0) {
        result += b * x * x;
        cout << "Evaluating quadratic term: " << b << "x^2" << endl;
    }
    if (c != 0) {
        result += c * x;
        cout << "Evaluating linear term: " << c << "x" << endl;
    }
    if (d != 0) {
        result += d;
        cout << "Evaluating constant term: " << d << endl;
    }

    return result;
}

int main() {
    double a, b, c, d, x;

    cout << "Enter coefficients a, b, c, d: ";
    cin >> a >> b >> c >> d;
    cout << "Enter the value of x: ";
    cin >> x;

    double result = evaluatePolynomial(a, b, c, d, x);
    cout << "Polynomial evaluated at x = " << x << " is: " << result << endl;

    return 0;
}
