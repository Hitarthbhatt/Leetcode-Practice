/*
            -> Container With Most Water <-

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

    Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,  3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        return getMaxVolume(height, 0, height.size() - 1, 0, 0);
    }

    int getMaxVolume(vector<int>& height, int left, int right, int leftOver, int maxSoFar) {

        if (left > right) {
            return maxSoFar;
        }

        int minHeight = min(height[left], height[right]);
        int totalWidth = right - left;
        int totalVolume = minHeight * totalWidth;

        maxSoFar = (totalVolume, maxSoFar);

        if (height[left] <= height[right]) {
            return getMaxVolume(height, left+1, right, leftOver+1, maxSoFar);
        } else {
            return getMaxVolume(height, left, right-1, leftOver+1, maxSoFar);
        }

    }

};

