#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

//双路快排
//针对存在大量重复数据做的优化
//包括所有针对基本有序数组排序做的优化

//双路快排整体排序性能比较好，对所有类型的数据排序效率均优于基础快排
//当存在大量重复数据时，排序效率不如三路快排

template<typename T>
void quickSort2Ways(T arr[], int n) {
    srand(time(nullptr));
    _quickSort2Ways(arr, 0, n - 1);
}

// 对arr[rangeL,rangeR]部分进行快速排序
template<typename T>
void _quickSort2Ways(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }

    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition2Ways(arr, rangeL, rangeR);

    _quickSort2Ways(arr, rangeL, index - 1);
    _quickSort2Ways(arr, index + 1, rangeR);
}

// 双路快速排序的partition
// 返回p, 使得arr[rangeL，index] <= arr[index] ; arr[index+1，rangeR] >= arr[index]
// 双路快排处理的元素正好等于arr[index]的时候要注意，详见下面的注释：）
template<typename T>
int _quickPartition2Ways(T arr[], int rangeL, int rangeR) {
    // 随机在arr[rangeR, rangeL]的范围中, 选择一个数值作为标定点pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];

    // arr[rangeL+1，i) <= temp; arr(j，rangeR] >= temp
    int i = rangeL + 1, j = rangeR;
    while (true) {
        // 注意这里的边界, arr[i] < temp, 不能是arr[i] <= temp
        // 思考一下为什么?
        while (i <= rangeR && arr[i] < temp)
            i++;

        // 注意这里的边界, arr[j] > temp, 不能是arr[j] >= temp
        // 思考一下为什么?
        while (j >= rangeL + 1 && arr[j] > temp)
            j--;

        // 对于上面的两个边界的设定, 有的同学在课程的问答区有很好的回答:)
        // 大家可以参考: http://coding.imooc.com/learn/questiondetail/4920.html

        if (i > j)
            break;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }


    swap(arr[j], arr[rangeL]);
    return j;
}