#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"

using namespace std;


// 比较Merge Sort和Quick Sort两种排序算法的性能效率
// 两种排序算法虽然都是O(nlogn)级别的, 但是Quick Sort算法有常数级的优势
// Quick Sort要比Merge Sort快, 即使我们对Merge Sort进行了优化
int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n);
    SortTestHelper::testSort("QuickSort2Ways", quickSort2Ways, arr4, n);
    SortTestHelper::testSort("QuickSort3Ways", quickSort3Ways, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout << endl;


    // 测试2 测试近乎有序的数组
    // 但是对于近乎有序的数组, 我们的快速排序算法退化成了O(n^2)级别的算法
    // 思考一下为什么对于近乎有序的数组, 快排退化成了O(n^2)的算法? :)
        int swapTimes = 100;
        cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
        arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
        arr2 = SortTestHelper::copyIntArray(arr1, n);
        arr3 = SortTestHelper::copyIntArray(arr1, n);
        arr4 = SortTestHelper::copyIntArray(arr1, n);
        arr5 = SortTestHelper::copyIntArray(arr1, n);
    
        SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
        SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
        SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n);
        SortTestHelper::testSort("QuickSort2Ways", quickSort2Ways, arr4, n);
        SortTestHelper::testSort("QuickSort3Ways", quickSort3Ways, arr5, n);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;

        cout << endl;

        // 测试3 测试存在包含大量相同元素的数组
        // 但此时, 对于含有大量相同元素的数组, 我们的快速排序算法再次退化成了O(n^2)级别的算法
        // 思考一下为什么在这种情况下, 快排退化成了O(n^2)的算法? :)
            cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
            arr1 = SortTestHelper::generateRandomArray(n,0,10);
            arr2 = SortTestHelper::copyIntArray(arr1, n);
            arr3 = SortTestHelper::copyIntArray(arr1, n);
            arr4 = SortTestHelper::copyIntArray(arr1, n);
            arr5 = SortTestHelper::copyIntArray(arr1, n);

            SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
            //SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
            //SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n);
            SortTestHelper::testSort("QuickSort2Ways", quickSort2Ways, arr4, n);
            SortTestHelper::testSort("QuickSort3Ways", quickSort3Ways, arr5, n);

            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
            delete[] arr4;
            delete[] arr5;

    system("pause");

    return 0;
}
