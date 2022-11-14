#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void indirectSort() {
    string value;
    int n;

    cin >> n;
    cin >> value;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (value[i] == 'Q') {
            count++;
        } else {
            count--;
        }

        if (count < 0) count = 0;
    }
    
    if (count == 0) {
        cout << "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }

}

int main() {

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        indirectSort();    
    }

    return 0;
}