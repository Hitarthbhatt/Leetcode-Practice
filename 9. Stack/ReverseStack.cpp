#include <iostream>
#include <stack>
 
using namespace std;
 
void insertAtBottom(stack<int> &stack, int element) {
    if (stack.empty()) {
        stack.push(element);
        return;
    }
    
    int num = stack.top();
    stack.pop();

    insertAtBottom(stack, element);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main() {
 
    stack<int> s;

    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }

    for (; !s.empty(); s.pop()) {
        cout << s.top() << " "; 
    }

    cout << endl;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }

    reverseStack(s);

    for (; !s.empty(); s.pop()) {
        cout << s.top() << " "; 
    }

    return 0;
}