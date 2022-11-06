/*
  -> Longest Substring Without Repeating Characters <-

 Given a string s, find the length of the longest substring without repeating characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
 */

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string result = "";
        int maxSubCount = 0;
        
        for (int i = 0; i < s.length(); i++) {

            char value = s[i];
            if (result.find(value) < result.length()) {
                int index = result.find(value); // Find index of pehle se pada hua char.
                maxSubCount = maxSubCount > result.length() ? maxSubCount : result.length();
                result.erase(0, index + 1); // Erase pehle se pada hua char and uske pehle wale.
            }
            result.push_back(value);
        }

        return maxSubCount > result.length() ? maxSubCount : result.length();;
    }
};