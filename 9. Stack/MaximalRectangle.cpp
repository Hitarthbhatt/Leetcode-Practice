/*
                    -> Maximal Rectangle <-

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
*/


#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

class Solution {
    private:
    vector<int> nextSmallerElement(vector<int> &arr, int n) {

        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr, int n) {

        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights, int n) {
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {

            int l = heights[i];
            if (next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;

            int ans = l*b;
            area = max(ans, area);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        vector<vector<int>> m(rowSize, vector<int>(colSize, 0));
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                m[i][j] = matrix[i][j] - '0';
            }
        }
        
        int area = largestRectangleArea(m[0], colSize);
     
        for (int i = 1; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                
                if (m[i][j] != 0) {
                    m[i][j] += m[i-1][j];
                } else {
                    m[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(m[i], colSize));
        }
        
        return area;
    }
};