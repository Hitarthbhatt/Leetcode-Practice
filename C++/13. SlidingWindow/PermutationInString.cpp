/*
                    -> Permutation in String <-

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkMatching(int count1[], int count2[]) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) 
            return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int count[26] = {0};
        int size = s1.length();

        for (int i = 0; i < size; i++) {
            int index = s1[i] - 'a';
            count[index]++;
        }

        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        while (i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        if (checkMatching(count, count2)) 
            return true;

        while (i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            if (checkMatching(count, count2)) 
                return true;
        }
        
        return false;
    }
};