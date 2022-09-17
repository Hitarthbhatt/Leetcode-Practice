#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int key) {

    int start = 0;
    int end = nums.size() - 1;

    int mid = start + (end - start)/2; // What if value comes greater than int max size. (Optimized Solution)

    while (start <= end) {

        if (key == nums[mid]) {
            return mid;
        } else if (key < nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
} 

int main() {
	vector<int> nums;
	
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(56);
    nums.push_back(57);
    nums.push_back(80);

    int result = binarySearch(nums, 10);

    cout << "10 found at - " << result;
	
	return 0; 
}