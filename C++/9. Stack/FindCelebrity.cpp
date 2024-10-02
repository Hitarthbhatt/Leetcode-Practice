/*
                    -> Find Celebrity <-

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

    Example 1:
    Input:
    N = 3
    M[][] = {{0 1 0},
            {0 0 0}, 
            {0 1 0}}
    Output: 1
    Explanation: 0th and 2nd person both
    know 1. Therefore, 1 is the celebrity. 
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
    bool knows(vector<vector<int> >& m, int a, int b) {
        if (m[a][b] == 1) {
            return true;
        }
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if (knows(m, a, b)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }
        
        int candidate = s.top();
        
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (m[candidate][i] == 0) zeroCount++;
        }
        
        if (zeroCount != n) return -1;
        
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (m[i][candidate] == 1) oneCount++;
        }
        
        if (oneCount != n - 1) return -1;
        
        return candidate;
    }
};