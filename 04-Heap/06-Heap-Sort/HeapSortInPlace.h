#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

// 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
template<typename T>
void heapSortInPlace(T arr[], int n) {
    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for (int i = (n - 2) / 2; i >= 0; i--) {
        _shiftDown(arr, n, i);
    }

    //当堆中只有一个元素的时候就不用交换了
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        _shiftDown(arr, i, 0);
    }
}

// 原始的shiftDown过程
template<typename T>
void _shiftDown(T arr[],int n,int key) {
    //左子节点不越界
    while (2 * key + 1 < n) {
        int next = 2 * key + 1;
        if (next + 1 < n && arr[next] < arr[next + 1]) {
            next++;
        }

        if (arr[key] >= arr[next]) {
            break;
        }

        swap(arr[key], arr[next]);
        key = next;
    }
}

template<typename T>
void heapSortInPlace2(T arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        _shiftDown2(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        _shiftDown2(arr, i, 0);
    }
}

// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
template<typename T>
void _shiftDown2(T arr[], int n, int key) {
    T v = arr[key];

    while (2 * key + 1 < n) {
        int next = 2 * key + 1;
        if (next + 1 < n && arr[next] < arr[next + 1]) {
            next++;
        }

        if (v >= arr[next]) {
            break;
        }
        arr[key] = arr[next];
        key = next;
    }

    arr[key] = v;
}