
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool isVowel(char& ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        return true;
    }
    return false;
}

int main() {

    string s;
    string result;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        char ch = tolower(s[i]);
        if (!isVowel(ch)) {
            result.push_back('.');
            result.push_back(ch);
        }
    }

    cout << result;

    return 0;
}