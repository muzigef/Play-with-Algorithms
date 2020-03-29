#include "BinarySearch.h"
#include <ctime>


int main() {
    /*===============================================================================================
     比较非递归和递归写法的二分查找的效率
     非递归算法在性能上有微弱优势
    ==================================================================================================*/

    /*int n = 1000000;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    delete[] a;*/

    /*===============================================================================================
     测试我们用二分查找法实现的floor和ceil两个函数
     请仔细观察在我们的测试用例中，有若干的重复元素，对于这些重复元素，floor和ceil计算结果的区别：）
    ==================================================================================================*/
    int a[] = { 1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6 };
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i <= 8; i++) {

        int floorIndex = binarySearchFloor(a, n, i);
        cout << "the floor index of " << i << " is " << floorIndex << ".";
        if (floorIndex >= 0 && floorIndex < n)
            cout << "The value is " << a[floorIndex] << ".";
        cout << endl;

        int ceilIndex = binarySearchCeil(a, n, i);
        cout << "the ceil index of " << i << " is " << ceilIndex << ".";
        if (ceilIndex >= 0 && ceilIndex < n)
            cout << "The value is " << a[ceilIndex] << ".";
        cout << endl;

        cout << endl;
    }

    system("pause");
    return 0;
}