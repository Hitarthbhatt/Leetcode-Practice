/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

  Example 1:
  
  Input: s1 = "ab", s2 = "eidbaooo"
  Output: true
  Explanation: s2 contains one permutation of s1 ("ba").
 */

#include<iostream>
#include<string>

using namespace std;

class Solution {

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

        // First stores all sub string character count.
        for (int i = 0; i < size; i++) {
            int index = s1[i] - 'a';
            count[index]++;
        }

        // Traverse s2 string in window of s1 length and compare.
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        // Running for the first window. 
        while (i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        // Check karo ki initially hi match ho gyi kya.
        if (checkMatching(count, count2)) 
            return true;

        // Again move window by 1 step and clear out first index.
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
