/*
            -> Pow(x, n) <-

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000
   
    Example 2:
    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double getPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        
        if (n == 1) {
            return x;   
        }
        
        double ans = myPow(x, n/2);;
        
        if (n&1) { // If power is odd.
            return ans * ans * x;
        } else {
            return ans * ans;
        }
    }
    
    double myPow(double x, int n) {
        double power = getPow(x, abs(n));
        return n < 0 ? 1/power : power;
    }
};