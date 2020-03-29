#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "MergeSortAdvance.h"
#include "MergeSortBU.h"

using namespace std;

// �Ƚ�Merge Sort��Merge Sort Bottom Up���������㷨������Ч��
// �������, �����㷨��Ч���ǲ��ġ��������������ϸ����, �Ե����ϵĹ鲢�������ʤһ�
// ����ϸ�Ĳ���, ���Բο��γ̵��������: http://coding.imooc.com/learn/questiondetail/3208.html
// ���½ڵĴ����Ҳ���������ϸ�Ĳ��Դ���

int main() {
    int n = 1000000;

    // ����1 һ���Բ���
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


    // ����2 ���Խ������������
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
