/*
                -> Rat In Maze <-

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

    Example 1:
    Input: N = 4
           m[][] = {{1, 0, 0, 0},
                    {1, 1, 0, 1}, 
                    {1, 1, 0, 0},
                    {0, 1, 1, 1}}
    Output: DDRDRR DRDDRR

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
    
    bool isSafe(int x, int y, int n, vector<vector<int>> visiting, vector<vector<int>>& m) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visiting[x][y] == 0 && m[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }
    
    void getPath(vector<vector<int>> &m, int n, int x, int y, vector<string>& ans, 
                 vector<vector<int>> visiting, string path) {
        
        if (x >= n - 1 && y >= n - 1) {
            ans.push_back(path);
            return;
        }
        
        visiting[x][y] = 1;
        
        // Down
        int newX = x + 1;
        int newY = y;
        
        if (isSafe(newX, newY, n, visiting, m)) {
            path.push_back('D');
            getPath(m, n, newX, newY, ans, visiting, path);
            path.pop_back();
        }
        
        // Left
        newX = x;
        newY = y - 1;
        
        if (isSafe(newX, newY, n, visiting, m)) {
            path.push_back('L');
            getPath(m, n, newX, newY, ans, visiting, path);
            path.pop_back();
        }
        
        // Right
        newX = x;
        newY = y + 1;
        
        if (isSafe(newX, newY, n, visiting, m)) {
            path.push_back('R');
            getPath(m, n, newX, newY, ans, visiting, path);
            path.pop_back();
        }
    
        // Up
        newX = x - 1;
        newY = y;
        
        if (isSafe(newX, newY, n, visiting, m)) {
            path.push_back('U');
            getPath(m, n, newX, newY, ans, visiting, path);
            path.pop_back();
        }
        
        visiting[x][y] = 0;
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int srcX = 0;
        int srcY = 0;
        string path = "";
        
        if (m[0][0] == 0) return ans;
        
        vector<vector<int>> visiting = m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visiting[i][j] = 0;
            }
        }
        getPath(m, n, srcX, srcY, ans, visiting, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};