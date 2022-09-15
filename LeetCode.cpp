#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
} 

int main() {
	vector<int> nums;
	int input, value;

    cin >> input;
    for (int i = 0; i < input; i++) {
        cin >> value;
        nums.push_back(value);
    }
	
	moveZeroes(nums);
	
	return 0; 
}