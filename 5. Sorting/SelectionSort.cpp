#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& nums) {
    int size = nums.size() - 1;

    for(int i = 0; i < size; i++) {
        int minIndex = i;

        for(int j = i + 1; j <= size; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        swap(nums[minIndex], nums[i]);
    }
}

int main() {

    vector<int> nums;

    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(1);

    selectionSort(nums);

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

	return 0;
}
