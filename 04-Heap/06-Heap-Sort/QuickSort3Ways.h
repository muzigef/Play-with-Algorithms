#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

//三路快排只对有大量重复数据的排序效率比较高，
//普通数据或者基本有序的数据效率还不如双路快排和基础快排
template<typename T>
void quickSort3Ways(T arr[],int n) {
    _quickSort3Ways(arr, 0, n - 1);
}

// 对arr[rangeL,rangeR]部分进行快速排序
template<typename T>
void _quickSort3Ways(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }
    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    // 随机在arr[rangeR, rangeL]的范围中, 选择一个数值作为标定点pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];

    int lt = rangeL;     // arr[rangeL+1,lt] < temp
    int gt = rangeR + 1; // arr[gt...rangeR] > temp
    int i = rangeL + 1;    // arr[lt+1...i) == temp
    while (i < gt) {
        if (arr[i] < temp) {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        }
        else if (arr[i] > temp) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        }
        else { // arr[i] == temp
            i++;
        }
    }

    //交换之后arr[lt] = temp 
    swap(arr[rangeL], arr[lt]); 

    _quickSort3Ways(arr, rangeL, lt - 1);
    _quickSort3Ways(arr, gt, rangeR);
}
