
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

long long getEndPoint(long long num) {
        long long result = 0;
        int count = 0;
        
        while (num >= 10) {
            int ans = num % 10;
            result += ans * pow(10, count++); 
            num = num / 10;
        }
        
        return result;
}


int main() {

    int end = 491;

    while (end > 0) {
        end = getEndPoint(end);
        cout << end << endl;
    }

    return 0;
}