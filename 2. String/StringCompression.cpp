/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

    Example 1:

    Input: chars = ["a","a","b","b","c","c","c"]
    Output: Return 6, and the first 6 characters of the input array should be: ["a",    "2","b","2","c","3"]
    Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ansCount = 0;
        int size = chars.size();
        int i = 0;

        while (i < size) {
            int j = i + 1;

            while (j < size && chars[i] == chars[j]) {
                j++;
            }
            // Yaha kab aaoge.
            // Ya to pura vecter traverse kar diya
            // ya fir new character found kar diya hai

            chars[ansCount++] = chars[i];

            int count = j - i;

            if (count > 1) {
                // Converting int value to character and store it.
                string cht = to_string(count);
                for(char ch: cht) {
                    chars[ansCount++] = ch;
                }
             }
            
            i = j;
        }
        
        return ansCount;
    }
};