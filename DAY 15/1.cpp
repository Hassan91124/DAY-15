#include <iostream>

using namespace std;

// Custom structure for complex numbers
template<typename T>
struct Complex {
    T real;
    T imag;
};

// Function to add two complex numbers
template<typename T>
Complex<T> add(Complex<T> a, Complex<T> b) {
    return {a.real + b.real, a.imag + b.imag};
}

// Function to subtract two complex numbers
template<typename T>
Complex<T> subtract(Complex<T> a, Complex<T> b) {
    return {a.real - b.real, a.imag - b.imag};
}

// Function to multiply two complex numbers
template<typename T>
Complex<T> multiply(Complex<T> a, Complex<T> b) {
    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

// Function to divide two complex numbers
template<typename T>
Complex<T> divide(Complex<T> a, Complex<T> b) {
    if (b.real == 0 && b.imag == 0) {
        throw runtime_error("Division by zero");
    }
    T denominator = b.real * b.real + b.imag * b.imag;
    return {
        (a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator
    };
}

int main() {
    Complex<double> num1{4, 3};
    Complex<double> num2{2, -1};

    try {
        Complex<double> result;

        result = add(num1, num2);
        cout << "Addition: " << result.real << " + " << result.imag << "i" << endl;

        result = subtract(num1, num2);
        cout << "Subtraction: " << result.real << " + " << result.imag << "i" << endl;

        result = multiply(num1, num2);
        cout << "Multiplication: " << result.real << " + " << result.imag << "i" << endl;

        result = divide(num1, num2);
        cout << "Division: " << result.real << " + " << result.imag << "i" << endl;

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
