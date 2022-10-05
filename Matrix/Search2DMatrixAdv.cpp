/*
                -> Search a 2D Matrix II <-

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
    Example 1:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],  target = 5
    Output: true      
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int row = 0;
        int col = colSize - 1;

        while(row < rowSize && col >= 0) {

            int element = matrix[row][col];

            if (element == target) {
                return true;
            } else if (element > target) {
                col--;
            } else {
                row++;
            }

        }
        
        return false;
    }
};

