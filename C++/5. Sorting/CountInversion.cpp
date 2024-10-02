/*
    Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

    Given an array a[]. The task is to find the inversion count of a[]. Wher two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

*/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int start, int end) {

    int inversion = 0;
    int mid = start + (end - start) / 2;

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
            inversion += len1 - index1;
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

int mergeSort(vector<int> &arr, int start, int end) {

    int mid = start + (end - start) / 2;
    int inversion = 0;

    if (start >= end) {
        return;
    }

    inversion += mergeSort(arr, start, mid);
    inversion += mergeSort(arr, mid + 1, end);

    inversion += merge(arr, start, end);

    return inversion;
}