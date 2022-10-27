/*
                -> Count and Say <-

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

Given a positive integer n, return the nth term of the count-and-say sequence.

    Input: n = 4
    Output: "1211"
    Explanation:
    countAndSay(1) = "1"
    countAndSay(2) = say "1" = one 1 = "11"
    countAndSay(3) = say "11" = two 1's = "21"
    countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string ans = "";
        convertAndSay(n, ans);
        return ans;
    }

    void convertAndSay(int num, string& ans) {

        if (num == 1) {
            ans = '1';
            return;
        }

        convertAndSay(num - 1, ans);

        string result = "";
        int numCounter = 1;

        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i+1]) {
                numCounter++;
            } else {
                result += to_string(numCounter);
                result.push_back(ans[i]);
                numCounter = 1;
            }
        }

        result += to_string(numCounter);
        result.push_back(ans[ans.size() - 1]);

        ans = result;
    }

};
// @lc code=end

