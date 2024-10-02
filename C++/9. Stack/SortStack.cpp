#include <iostream>
#include <stack>
 
using namespace std;
 
void sortedInsert(stack<int> &stack, int element) {
    if (stack.empty() || stack.top() < element) {
        stack.push(element);
        return;
    }
    
    int num = stack.top();
    stack.pop();

    sortedInsert(stack, element);

    stack.push(num);
}

void sortStack(stack<int> &stack) {
    // base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack, num);
}

int main() {
 
    stack<int> s;

    for (int i = 10; i >= 0; i--) {
        s.push(i);
    }

    for (; !s.empty(); s.pop()) {
        cout << s.top() << " "; 
    }

    cout << endl;
    for (int i = 10; i >= 0; i--) {
        s.push(i);
    }

    sortStack(s);

    for (; !s.empty(); s.pop()) {
        cout << s.top() << " "; 
    }

    return 0;
}