#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(nullptr));
    _quickSort(arr, 0, n - 1);
}

// 对arr[rangeL,rangeR]部分进行快速排序
template<typename T>
void _quickSort(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }
    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition(arr, rangeL, rangeR);

    _quickSort(arr, rangeL, index - 1);
    _quickSort(arr, index + 1, rangeR);
}

// 对arr[rangeL,rangeR]部分进行_quickPartition操作
// 返回index, 使得arr[rangeL, index - 1] < arr[index] ; arr[index + 1, rangeR] > arr[index]
template<typename T>
int _quickPartition(T arr[], int rangeL, int rangeR) {
    // 随机在arr[rangeR, rangeL]的范围中, 选择一个数值作为标定点pivot
    //思考：为什么该方式能够有效优化基本有序数组的排序呢？
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];
    int j = rangeL;

    for (int i = rangeL + 1; i <= rangeR; i++) {
        if (arr[i] < temp) {
            j++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[rangeL]);
    return j;
}

//首先找出第一个大于arr[rangeL]，从该值开始排序，能提升基本有序数组的排序效率
//自己做的优化
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(nullptr));
    _quickSort2(arr, 0, n - 1);
}

// 对arr[rangeL,rangeR]部分进行快速排序
template<typename T>
void _quickSort2(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }

    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition2(arr, rangeL, rangeR);

    _quickSort2(arr, rangeL, index - 1);
    _quickSort2(arr, index + 1, rangeR);
}

template<typename T>
int _quickPartition2(T arr[], int rangeL, int rangeR) {
    // 随机在arr[rangeR, rangeL]的范围中, 选择一个数值作为标定点pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];
    int j = rangeL;

    //首先找出第一个大于arr[rangeL]，从该值开始排序，能提升基本有序数组的排序效率
    for (int i = rangeL + 1; i <= rangeR; i++) {
        if (arr[i] >= temp) {
            j = i - 1;
            break;
        }
    }

    for (int i = j + 1; i <= rangeR; i++) {
        if (arr[i] < temp) {
            j++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[rangeL]);
    return j;
}

