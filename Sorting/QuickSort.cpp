#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int low, int high);
int partitionArray(vector<int>& nums, int low, int high);
void swapValues(vector<int>& nums, int firstIndex, int secondIndex);

void quickSort(vector<int>& nums, int low, int high) {
	
	int partitionPoint;
	
	if ((high - low) > 0) {
		
		partitionPoint = partitionArray(nums, low, high); // Finds perfect places for selected pivot.
		quickSort(nums, low, partitionPoint-1);
		quickSort(nums, partitionPoint+1, high);
	}
	
}

int partitionArray(vector<int>& nums, int low, int high) {
	
	int index;
	int pivot;
	int firstHigh;
	
	pivot = high; // 5 4 8 10 6 9 1 7
	firstHigh = low;
	
	for (index = low; index < high; index++) {
		if (nums[index] < nums [pivot]) {
			swapValues(nums, index, firstHigh);
			firstHigh++;
		}
	}
	
	swapValues(nums, pivot, firstHigh);
	
	return firstHigh;
}

void swapValues(vector<int>& nums, int firstIndex, int secondIndex) {
	int temp = nums[firstIndex];
	nums[firstIndex] = nums[secondIndex];
	nums[secondIndex] = temp;
}

int main() {
	return 0;
}
