
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void isPalindrome(string first, string second) {

    int start = 0;
    int end = first.length() - 1;

    while(start <= end) {
        swap(first[start++], first[end--]);
    }

    if (first == second) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}



int main() {

    string first, second;

    cin >> first >> second;

    isPalindrome(first, second);

    return 0;
}