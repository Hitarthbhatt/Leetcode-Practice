//              -> SegmentedSieve <-

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieveOfEratasthenes(vector<int>& primes, int n) {
        
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = 2*i; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

vector<int> segmentedSieve(long long left, long long right) {

    vector<int> primes;
    vector<bool> isPrime(right - left + 1, true);

    int limit = floor(sqrt(right)) + 1;
    sieveOfEratasthenes(primes, limit);

    for (int i = 0; primes[i] * primes[i] <= right; i++) {
        int currentPrime = primes[i];

        // Just smaller or equal to left.
        long long base = (left / currentPrime) * currentPrime;
        base = base < left ? base + currentPrime : base;

        // Mark all multiple of primes within Left - Right into false;
        for (int j = base; base <= right; base += currentPrime) {
            isPrime[j - left] = false;
        }

        if (base == currentPrime) {
            isPrime[base - left] = true;
        }
    }
    

    for (int i = 0; i <= right - left; i++) {
        if (isPrime[i]) {
            primes.push_back(i + left);
        }
    }
    
    cout << "working";
    return primes;
}

int main() {
    vector<int> primes;

    primes = segmentedSieve(10, 16);

    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }

    return 0;
}