#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
  public:
    int get(int index);
    int length();
};

int findInMountainArray(int target, MountainArray &mountainArr) {
        int pickIndex = getPeakIndexInMountainArray(mountainArr);

        int left = binarySearch(mountainArr, target, 0, pickIndex);
        int right = resverseBinarySearch(mountainArr, target, pickIndex + 1, mountainArr.length() - 1);

        int minPosition = min(left, right);

        if (minPosition == INT_MAX) return -1;

        return minPosition;
    }

int getPeakIndexInMountainArray(MountainArray &mountainArr) {
    int start = 0;
    int end = mountainArr.length() - 1;
    int mid = start + (end - start)/2;
    while (start < end)  {
        if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    
    return start;
}

int binarySearch(MountainArray &mountainArr, int key, int start, int end) {
    int mid = start + (end - start)/2;
    int result = INT_MAX;

    while (start <= end) {
        if (key == mountainArr.get(mid)) {
            result = mid;
            end = mid - 1;
        } else if (key < mountainArr.get(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }
    return result;
} 
int resverseBinarySearch(MountainArray &mountainArr, int key, int start, int end) {
    int mid = start + (end - start)/2;
    int result = INT_MAX;

    while (start <= end) {
        if (key == mountainArr.get(mid)) {
            result = mid;
            start = mid + 1;
        } else if (key < mountainArr.get(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return result;
}