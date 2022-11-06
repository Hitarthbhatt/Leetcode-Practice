#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start, int end) {
    
    int mid = start + (end - start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = start;

    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];       
    }

    mainArrayIndex = mid + 1;

    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete [] first;
    delete [] second;
}

void mergeSort(vector<int>& arr, int start, int end) {

    int mid = start + (end - start)/2;

    if (start >= end) {
        return;
    }

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);
}

int main() {

    vector<int> nums;

    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(1);

    mergeSort(nums, 0, nums.size()-1);

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

	return 0;
}
