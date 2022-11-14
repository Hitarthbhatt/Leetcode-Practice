
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


int main() {

    int n = 3;

    int newVal = n & n - 1;

    cout << (n && !newVal) << endl;

    return 0;
}