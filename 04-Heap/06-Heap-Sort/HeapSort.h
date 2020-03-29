#pragma once

#include "MaxHeap.h"

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap(n);
    for (int i = 0; i < n; i++) {
        maxheap.insert(arr[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}