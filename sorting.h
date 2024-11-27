#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <list>
#include <cctype>
#include <algorithm>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
using namespace std;

// Bubble Sort for any data type T
template <typename T>
int bubbleSort(vector<T>& data, bool (*compareFunc)(const T&, const T&)) {
    int passes = 0;
    bool swapped;
    for (size_t i = 0; i < data.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            passes++; // Count each comparison as a pass
            if (compareFunc(data[j], data[j + 1])) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no elements were swapped, the array is sorted
    }
    return passes;
}

template <typename T>
int insertionSort(vector<T>& data, bool (*compareFunc)(const T&, const T&)) {
    int passes = 0;
    for (size_t i = 1; i < data.size(); ++i) {
        T key = data[i];
        size_t j = i - 1;
        // Shift elements of data[0..i-1] that are greater than key to one position ahead
        while (j < data.size() && compareFunc(key, data[j])) {
            passes++; // Count each comparison as a pass
            data[j + 1] = data[j];
            j--;
        }
        // Insert the key at the correct position
        data[j + 1] = key;
    }
    return passes;
}


// Selection Sort for any data type T
template <typename T>
int selectionSort(vector<T>& data, bool (*compareFunc)(const T&, const T&)) {
    int passes = 0;
    for (size_t i = 0; i < data.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            passes++; // Count each comparison as a pass
            if (compareFunc(data[j], data[minIndex])) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
    return passes;
}


// Quick Sort with comparison function and pass counting
template <typename T>
int partition(vector<T>& items, int low, int high, bool (*compareFunc)(const T&, const T&), int& passCount) {
    T pivot = items[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        passCount++;  // Count each comparison as a pass
        if (compareFunc(items[j], pivot)) {
            i++;
            swap(items[i], items[j]);
        }
    }
    swap(items[i + 1], items[high]);
    return i + 1;
}

template <typename T>
int quickSort(vector<T>& items, int low, int high, bool (*compareFunc)(const T&, const T&)) {
    int passCount = 0;
    if (low < high) {
    int pi = partition(items, low, high, compareFunc, passCount);
    passCount += quickSort(items, low, pi - 1, compareFunc);
    passCount += quickSort(items, pi + 1, high, compareFunc);
}
    return passCount;
}


template <typename T>
void merge(vector<T>& items, int left, int mid, int right, bool (*compareFunc)(const T&, const T&), int& passCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i = 0, j = 0, k = left;
    
    // Temporary arrays for merging
    vector<T> L(items.begin() + left, items.begin() + mid + 1);
    vector<T> R(items.begin() + mid + 1, items.begin() + right + 1);

    while (i < n1 && j < n2) {
        passCount++;  // Count each comparison as a pass
        if (compareFunc(L[i], R[j])) {
            items[k] = L[i];
            i++;
        } else {
            items[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        items[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        items[k] = R[j];
        j++;
        k++;
    }
}


template <typename T>
int mergeSort(vector<T>& items, int left, int right, bool (*compareFunc)(const T&, const T&)) {
    int passCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        passCount += mergeSort(items, left, mid, compareFunc);
        passCount += mergeSort(items, mid + 1, right, compareFunc);
        merge(items, left, mid, right, compareFunc, passCount);
    }
    return passCount;
}