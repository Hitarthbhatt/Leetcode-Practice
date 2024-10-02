/*
                -> Super Pow <-

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

    Example 1:

    Input: a = 2, b = [3]
    Output: 8
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        
        int result = 1;
        
        for (int i = b.size() - 1; i >= 0; i--) {
            result = result * modularExpontiation(a, b[i], 1337) % 1337;   
            a = modularExpontiation(a, 10, 1337);
        }
        
        return result;
    }
    
    int modularExpontiation(int a, long long power, int moduler) {
        int result = 1;
        
        while (power > 0) {
            if (power & 1) {
                result = ((1ll) * (result) * (a) % moduler);
            }
            
            a = ((1ll) * (a) * (a) % moduler);
            power = power >> 1;
        }
        
        return result;
    }
    
};