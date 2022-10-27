/*
                      MOST IMPORTENT
                -> Permutation Sequence <- 

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

                "123"
                "132"
                "213"
                "231"
                "312"
                "321"
Given n and k, return the kth permutation sequence.

    Example 1:
    Input: n = 3, k = 3
    Output: "213"
 */

/*
                    Solution

Let us first take an example to under the idea:
Suppose n = 4.
So we have elements - 1,2,3,4
There are total n!= 4! = 24 permutations possible. We can see a specific pattern here:

        arr
        [ 1            2           3          4]
        1 2 3 4     2 1 3 4     3 1 2 4    4 1 2 3
        1 2 4 3     2 1 4 3     3 1 4 2    4 1 3 2
        1 3 2 4     2 3 1 4     3 2 1 4    4 2 1 3
        1 3 4 2     2 3 4 1     3 2 4 1    4 2 3 1
        1 4 2 3     2 4 1 3     3 4 1 2    4 3 1 2
        1 4 3 2     2 4 3 1     3 4 2 1    4 3 2 1
        So we have 4 block with 6 elements each.

        fact = {1,1,2,6,24,120,720,5040,40320,362880}

Step 1 :- Get the index of the block by -> { index = k / fact(n - 1) }
    Corner Case -> If fact(n - 1) is multiple of k (k % fact(n - 1) ==  0) then do { index-- }
    Ex. -> k = 12 & fact(n - 1) = fact(3) = 6 then index = 2 (ans = 3124) but real ans = 2431.

Step 2 :- Add index value from array to ans.
Step 3 :- Remove that value from array.
Step 4 :- Set new k value for remaining array.
Step 5 :- Repeat this process recursively.

Base Case :- if n == 1 then add array last value to 'ans' and return.

*/



#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    void getPermutations(vector<int>& nums, vector<int>& facts, int n, int& k, string& ans) {
        
        // Base case.
        if (n == 1) { // If all elements added to the ans. 
            ans += to_string(nums.back());
            return;
        }

        // We are calculating the required index.  factVal[n-1] means for n =  4 => factVal[3] = 6.
        // 15 / 6 = 2 will the index for k =15 and n = 4.
        int index = k / facts[n - 1]; // find block index 

        // if k is a multiple of elements of partition then decrement the index
        if (k % facts[n-1] == 0) { // Corner case.
            index--;
        }

        ans += to_string(nums[index]); // Now add the element to string.
        nums.erase(nums.begin() + index);  // Remove added element from original array.

        k -= facts[n - 1] * index; // Adjust k value for remaining array.

        // Finally recursive call for reamining array.
        getPermutations(nums, facts, n - 1, k, ans);

    }

    vector<int> getFactorials() {
        vector<int> result;
        int fact = 1;
        result.push_back(fact);
        for (int i = 1; i <= 9; i++) {
            fact *= i;
            result.push_back(fact);
        }
        return result;
    }

public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> facts;
        string result = "";

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        facts = getFactorials();

        getPermutations(nums, facts, n, k, result);


        return result;
    }
};

