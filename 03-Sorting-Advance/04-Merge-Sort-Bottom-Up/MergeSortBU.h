#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

// 使用自底向上的归并排序算法
// Merge Sort BU 也是一个O(nlogn)复杂度的算法，虽然只使用两重for循环
// 所以，Merge Sort BU也可以在1秒之内轻松处理100万数量级的数据
// 注意：不要轻易根据循环层数来判断算法的复杂度，Merge Sort BU就是一个反例
// 关于这部分陷阱，推荐看我的《玩转算法面试》课程，第二章：《面试中的复杂度分析》：）

//Merge Sort Bottom Up 无优化版本
template <typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz < n; sz += sz)  //sz为各个归并层的粒度
        //i < n - sz条件控制i + sz - 1不越界
        for (int i = 0; i < n - sz; i += sz + sz)  //当前归并层的各个归并单元
            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
            //min控制i + sz + sz - 1,不越界
            _mergeBU(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

//Merge Sort Bottom Up 优化版本
template <typename T>
void mergeSortBUAdvance(T arr[], int n) {

    // 对于小数组, 使用插入排序优化
    for (int i = 0; i < n; i += 16)
        insertionSort(arr, i, min(i + 15, n - 1));

    for (int sz = 16; sz < n; sz += sz)  //sz为各个归并层的粒度
        for (int i = 0; i < n - sz; i += sz + sz)  //当前归并层的各个归并单元
            // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
            if (arr[i + sz - 1] > arr[i + sz])
                _mergeBU(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

//归并[rangeL,center]和[center+1,rangeR]两段
template<typename T>
void _mergeBU(T arr[], int rangeL, int center, int rangeR) {
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
        else if (arr[i] < arr[j]) {   // 左半部分所指元素 < 右半部分所指元素
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