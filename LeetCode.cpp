
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

vector<int> segmentedSieve(int n) {

    vector<int> primes;
    long long left = floor(sqrt(n)) + 1;
    long long right = n;
    vector<bool> isPrime(right - left + 1, true);

    sieveOfEratasthenes(primes, left);

    for (int i = 0; i < primes.size(); i++) {
        int currentPrime = primes[i];

        // Just smaller or equal to left.
        long long base = (left / currentPrime) * currentPrime;
        if (base < left) {
            base = base + currentPrime;
        }
        cout << "Base is -> " << base << endl;
        // Mark all multiple of primes within Left - Right into false;
        for (int j = base; j <= right; j += currentPrime) {
            isPrime[j - left] = false;
            // cout << j - left << endl;
        }

        if (base == currentPrime) {
            isPrime[base - left] = true;
        }
    }
    

    for (int j = 0; j <= right - left; j++) {
        if (isPrime[j]) {
            primes.push_back(j + left);
        }
    }
    
    cout << "Total primes are ->" << primes.size() << endl;
    return primes;
}

int main() {
	vector<int> primes;

    cout << "Working" << endl;

    primes = segmentedSieve(160);

    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }
	return 0; 
}