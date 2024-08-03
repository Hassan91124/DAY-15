#include <iostream>
#include <vector>

using namespace std;

// Custom data structure for storing prime numbers
struct PrimeList {
    vector<int> primes;

    void add(int prime) {
        primes.push_back(prime);
    }

    void print() const {
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
};

// Function to generate prime numbers using the Sieve of Eratosthenes
PrimeList generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    PrimeList primeList;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primeList.add(p);
        }
    }

    return primeList;
}

int main() {
    int limit;
    cout << "Enter the limit to generate prime numbers: ";
    cin >> limit;

    PrimeList primes = generatePrimes(limit);
    cout << "Prime numbers up to " << limit << ": ";
    primes.print();

    return 0;
}
