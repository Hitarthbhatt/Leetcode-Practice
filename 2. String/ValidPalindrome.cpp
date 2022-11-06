/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include<iostream>
#include<string>

using namespace std;

class Solution {

private:
    bool isValid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }

        return false;
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool isPalindromeString(string s) {

        int start = 0;
        int end = s.length() - 1;

        while(start < end) {
            if (s[start] != s[end]) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string result = "";

        for (int j = 0; j < s.length(); j++) {
            if (isValid(s[j])) {
                result.push_back(s[j]);
            }
        }

        for (int j = 0; j < result.length(); j++) {
            result[j] = toLowerCase(result[j]);
        }

        return isPalindromeString(result);
    }
};