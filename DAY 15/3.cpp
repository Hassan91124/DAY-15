#include <iostream>
#include <limits>

using namespace std;

// Function to calculate factorial using recursion
unsigned long long factorial(int n, bool& overflow) {
    if (n < 0) {
        overflow = true;
        return 0;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    unsigned long long result = factorial(n - 1, overflow);

    if (overflow || result > numeric_limits<unsigned long long>::max() / n) {
        overflow = true;
        return 0;
    }

    return n * result;
}

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    bool overflow = false;
    unsigned long long result = factorial(n, overflow);

    if (overflow) {
        cout << "Error: Overflow occurred. Factorial result is too large to fit in an unsigned long long." << endl;
    } else {
        cout << "Factorial of " << n << " is: " << result << endl;
    }

    return 0;
}
