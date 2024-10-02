/*
                -> Count Primes <-

Given an integer n, return the number of prime numbers that are strictly less than n.

    Example 1: 
    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        
        int totalPrimes = 0;
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                totalPrimes++;
                for (int j = 2*i; j < n; j = j + i) {
                    isPrime[j] = false;
                }
            }
        }

        return totalPrimes;
    }
};

