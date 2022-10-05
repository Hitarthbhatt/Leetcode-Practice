/*
                    -> Rotate Image <-

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix[0].size();

        // Transpose the matrix.
        for (int row = 0; row < size; row++) {
            for (int col = row + 1; col < size; col++) {
                swap(matrix[row][col], matrix[col][row]);
                cout << matrix[col][row] << endl;
            }
        }

        // Reverse each row elements.
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size/2; col++) {
                swap(matrix[row][col], matrix[row][size - col - 1]);
            }
        }

    }
};

