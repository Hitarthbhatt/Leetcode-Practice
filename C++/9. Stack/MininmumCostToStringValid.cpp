#include <iostream>
#include <stack>
 
using namespace std;
 
int findMinimumCost(string str) {

    // Odd condition
    if (str.length() % 2 != 0) {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '{') {
            s.push(str[i]);
        } else {

            //ch is closed brace
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(str[i]);
            }
        }
    }

    // Stack contains invalid string.
    int a = 0, b = 0;

    while (!s.empty()) {
        char ch = s.top();
        s.pop();

        if (ch == '}') a++;
        else b++;
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;

    return ans;
}

int main() {

    int ans = findMinimumCost("}}}}{{{{");

    cout << ans << endl;

    return 0;
}