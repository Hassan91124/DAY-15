#include <iostream>
#include <vector>

using namespace std;

// Function to calculate Fibonacci sequence using memoization
unsigned long long fibonacci(int n, vector<unsigned long long>& memo) {
    if (n < memo.size()) {
        return memo[n];
    }

    for (int i = memo.size(); i <= n; i++) {
        memo.push_back(memo[i - 1] + memo[i - 2]);
    }

    return memo[n];
}

// Iterative fallback for large Fibonacci numbers
unsigned long long fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n;
    cout << "Enter the Fibonacci term to calculate: ";
    cin >> n;

    vector<unsigned long long> memo = {0, 1};

    unsigned long long result;
    if (n < 50) {
        result = fibonacci(n, memo);
    } else {
        result = fibonacciIterative(n);
    }

    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}
