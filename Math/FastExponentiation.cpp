#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fastExpontiation(int a, int power) {
        int result = 1;
        
        while (power > 0) {
            if (power & 1) { // If Odd.
                result = result * a;
            }
            
            a = a * a;
            power = power >> 1; // Right shift value.
        }
        
        return result;
    }
    
};