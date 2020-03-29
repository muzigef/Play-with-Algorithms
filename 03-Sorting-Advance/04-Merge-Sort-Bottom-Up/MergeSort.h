#pragma once

#include <cassert>
#include <algorithm>

template<typename T>
void mergeSort(T arr[], int n) {
    assert(n);
    _mergeSort(arr, 0, n - 1);
}

//递归使用归并排序,排序[rangeL,rangeR]范围内的元素,注意左右都是闭区间
template<typename T>
void _mergeSort(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR)
        return;

    int center = (rangeR - rangeL) / 2 + rangeL;
    _mergeSort(arr, rangeL, center);
    _mergeSort(arr, center + 1, rangeR);
    _merge(arr, rangeL, center, rangeR);
}

//归并[rangeL,center]和[center+1,rangeR]两段
template<typename T>
void _merge(T arr[], int rangeL, int center, int rangeR) {
    //i指向左半部分的起始索引位置rangeL；
    int i = rangeL;
    //j指向右半部分起始索引位置center + 1
    int j = center + 1;

    //初始化一个大小为rangeR - rangeL + 1的数组,用于存放排序后的元素
    //VS不支持动态长度数组, rangeL和rangeR值是未知的
    //即不能使用 T a[rangeR - rangeL + 1]的方式申请a的空间,需要使用new的方式
    T* a = new T[rangeR - rangeL + 1];

    for (int k = rangeL; k <= rangeR; k++) {
        if (i > center) {   // 如果左半部分元素已经全部处理完毕
            a[k - rangeL] = arr[j];
            j++;
        }
        else if (j > rangeR) {   // 如果右半部分元素已经全部处理完毕
            a[k - rangeL] = arr[i];
            i++;
        }
        else if(arr[i] < arr[j]) {   // 左半部分所指元素 < 右半部分所指元素
            a[k - rangeL] = arr[i];
            i++;
        }
        else {   // 左半部分所指元素 >= 右半部分所指元素
            a[k - rangeL] = arr[j];
            j++;
        }
    }

    //将排序后的元素赋值给arr
    for (int k = rangeL; k <= rangeR; k++) {
        arr[k] = a[k - rangeL];
    }

    delete[] a;  //删除new的数据a
}