#include <iostream>

using namespace std;

// Function to integrate another function using the trapezoidal rule
double adaptiveIntegrate(double (*func)(double), double a, double b, double tolerance) {
    double h = b - a;
    double result = (func(a) + func(b)) * h / 2.0;
    double previousResult = result;
    int iterations = 0;

    while (true) {
        double sum = 0.0;
        for (int i = 1; i <= (1 << iterations); i += 2) {
            sum += func(a + i * h / (1 << iterations));
        }
        result = previousResult / 2.0 + sum * h / (1 << (iterations + 1));
        
        if (abs(result - previousResult) < tolerance) {
            break;
        }

        previousResult = result;
        iterations++;
    }

    return result;
}

double exampleFunction(double x) {
    return x * x; // Example function: x^2
}

int main() {
    double a, b, tolerance;
    cout << "Enter the lower bound of integration: ";
    cin >> a;
    cout << "Enter the upper bound of integration: ";
    cin >> b;
    cout << "Enter the tolerance: ";
    cin >> tolerance;

    double result = adaptiveIntegrate(exampleFunction, a, b, tolerance);
    cout << "Result of integration: " << result << endl;

    return 0;
}
