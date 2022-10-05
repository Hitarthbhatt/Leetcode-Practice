/*
                -> Search a 2D Matrix <-

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

    Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
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
        
        int start = 0;
        int end = rowSize * colSize - 1;
        int mid = start + (end - start)/2;
        
        while (start <= end) {
            int element = matrix[mid / colSize][mid % colSize];
            
            if (element == target) {
                return true;
            } else if (element < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            
            mid = start + (end - start)/2;
        }
        
        return false;
    }
};

