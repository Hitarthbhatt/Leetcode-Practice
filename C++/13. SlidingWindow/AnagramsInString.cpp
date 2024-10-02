/*
                    -> Find All Anagrams in a String <-

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

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
    bool isFreqSame(vector<int> &s1, vector<int> &s2) {
        for (int i = 0; i < 26; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freqP(26);
        vector<int> freqS(26); 

        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < s.size()) {
            freqS[s[j] - 'a']++;

            if (j - i + 1 == p.size()) {
                if (isFreqSame(freqS, freqP)) {
                    ans.push_back(i);
                }
            }

            if (j - i + 1 < p.size()) j++;
            else {
                freqS[s[i] - 'a']--;
                i++;
                j++;
            }
        }

        return ans;
    }
};