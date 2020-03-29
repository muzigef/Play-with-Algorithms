#include "indexMaxHeap.h"
#include "SortTestHelper.h"


// 比较 Merge Sort, 三种 Quick Sort 和本节介绍的三种 Heap Sort 的性能效率
// 注意, 这几种排序算法都是 O(nlogn) 级别的排序算法
int main() {

    int n = 100;
    IndexMaxHeap<int> indexMaxHeap(n);

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    //SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
    for (int i = 0; i < n; i++) {
        indexMaxHeap.insert(i, arr[i]);
    }

    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = indexMaxHeap.extractMax();
    }

    for (int i = 0; i < n - 1; i++) {
        assert(result[i] >= result[i + 1]);
        cout << result[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    delete[] result;


    system("pause");
    return 0;
}