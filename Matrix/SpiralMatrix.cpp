/*
                    -> Spiral Matrix <-

 Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int traverser = 0;
        int total = rowSize * colSize;

        int startingCol = 0;
        int startingRow = 0;
        int endingCol = colSize - 1;
        int endingRow = rowSize - 1;

        vector<int> result;

        while (traverser < total) {

            // Print starting row.
            for (int index = startingCol; traverser < total && index <= endingCol; index++) {
                result.push_back(matrix[startingRow][index]);
                traverser++;
            } 
            startingRow++;

            // Print ending col.
            for (int index = startingRow; traverser < total && index <= endingRow; index++) {
                result.push_back(matrix[index][endingCol]);
                traverser++;
            } 
            endingCol--;

            // Print ending row.
            for (int index = endingCol; traverser < total && index >= startingCol; index--) {
                result.push_back(matrix[endingRow][index]);
                traverser++;
            } 
            endingRow--;

            // Print stating col.
            for (int index = endingRow; traverser < total && index >= startingRow; index--) {
                result.push_back(matrix[index][startingCol]);
                traverser++;
            } 
            startingCol++;
        }

        return result;
    }
};

