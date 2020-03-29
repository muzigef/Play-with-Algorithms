#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

//二分查找算法处理的必须是有序数列
template<typename T>
int binarySearch(T arr[], int n, T target) {
    //在[rangeL, rangeR]范围内查找元素
    int rangeL = 0;
    int rangeR = n - 1;

    while (rangeL <= rangeR) {
        //int mid = (rangeL + rangeR)/2;
        // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
        int mid = (rangeR - rangeL) / 2 + rangeL;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            //查找在[rangeL, mid - 1]范围内的元素
            rangeR = mid - 1;
        }
        else {
            //查找在[mid + 1, rangeR]范围内的元素
            rangeL = mid + 1;
        }
    }

    return -1;
}

// 用递归的方式写二分查找法
template<typename T>
int binarySearch2(T arr[], int n, T target) {
    return _binarySearch2(arr, 0, n - 1, target);
}

//在[rangeL, rangeR]范围内查找元素
template<typename T>
int _binarySearch2(T arr[], int rangeL, int rangeR, T target) {
    if (rangeL > rangeR) {
        return -1;
    }

    //int mid = (rangeL+rangeR)/2;
    // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
    int mid = (rangeR - rangeL) / 2 + rangeL;

    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        //查找在[rangeL, mid - 1]范围内的元素
        return _binarySearch2(arr, rangeL, mid - 1, target);
    }
    else {
        //查找在[mid + 1, rangeR]范围内的元素
        return _binarySearch2(arr, mid + 1, rangeR, target);
    }
}

// 二分查找法, 在有序数组arr中, 查找target
// 如果找到target, 返回第一个target相应的索引index
// 如果没有找到target, 返回比target小的最大值相应的索引, 如果这个最大值有多个, 返回最大索引
// 如果这个target比整个数组的最小元素值还要小, 则不存在这个target的floor值, 返回-1
template<typename T>
int binarySearchFloor(T arr[], int n, T target) {
    assert(n >= 0);

    // 寻找比target小的最大索引
    int rangeL = -1; //如果这个target比整个数组的最小元素值还要小, 则不存在这个target的floor值, 返回-1
    int rangeR = n - 1;
    while (rangeL < rangeR) {
        // 使用向上取整避免死循环
        int mid = rangeL + (rangeR - rangeL + 1) / 2;
        if (arr[mid] >= target)
            rangeR = mid - 1;
        else
            rangeL = mid;  //注意不是mid+1，因为当不存在时，需要取target小的最大值相应的索引
    }

    assert(rangeL == rangeR);

    // 如果该索引+1就是target本身, 该索引+1即为返回值
    if (rangeL + 1 < n && arr[rangeL + 1] == target)
        return rangeL + 1;

    // 否则, 该索引即为返回值
    return rangeL;
}

// 二分查找法, 在有序数组arr中, 查找target
// 如果找到target, 返回最后一个target相应的索引index
// 如果没有找到target, 返回比target大的最小值相应的索引, 如果这个最小值有多个, 返回最小的索引
// 如果这个target比整个数组的最大元素值还要大, 则不存在这个target的ceil值, 返回整个数组元素个数n
template<typename T>
int binarySearchCeil(T arr[], int n, T target) {
    assert(n >= 0);

    // 寻找比target大的最小索引
    int rangeL = 0;
    int rangeR = n; //如果这个target比整个数组的最大元素值还要大, 则不存在这个target的ceil值, 返回整个数组元素个数n
    while (rangeL < rangeR) {
        // 使用向下取整避免死循环
        int mid = rangeL + (rangeR - rangeL ) / 2;
        if (arr[mid] <= target)
            rangeL = mid + 1;
        else  // arr[mid] > target
            rangeR = mid; //注意不是mid-1，因为当不存在时，需要比target大的最小值相应的索引
    }

    assert(rangeL == rangeR);

    // 如果该索引-1就是target本身, 该索引-1即为返回值
    if (rangeR - 1 < n && arr[rangeR - 1] == target)
        return rangeR - 1;

    // 否则, 该索引即为返回值
    return rangeR;
}
