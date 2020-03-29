#include "indexMaxHeap.h"
#include "SortTestHelper.h"


// �Ƚ� Merge Sort, ���� Quick Sort �ͱ��ڽ��ܵ����� Heap Sort ������Ч��
// ע��, �⼸�������㷨���� O(nlogn) ����������㷨
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