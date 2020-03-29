#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "MergeSortAdvance.h"
#include "MergeSortBU.h"

using namespace std;

// 比较Merge Sort和Merge Sort Bottom Up两种排序算法的性能效率
// 整体而言, 两种算法的效率是差不多的。但是如果进行仔细测试, 自底向上的归并排序会略胜一筹。
// 更详细的测试, 可以参考课程的这个问题: http://coding.imooc.com/learn/questiondetail/3208.html
// 本章节的代码仓也会给出更详细的测试代码

int main() {
    int n = 1000000;

    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);
    SortTestHelper::testSort("Merge Sort Bottom Up Advance", mergeSortBUAdvance, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);
    SortTestHelper::testSort("Merge Sort Bottom Up Advance", mergeSortBUAdvance, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    system("pause");

    return 0;
}
