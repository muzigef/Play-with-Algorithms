#include <iostream>
#include "InsertionSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// �Ƚ�InsertionSort��MergeSort���������㷨������Ч��
// �������, MergeSort����������, ���ڽ��������������������, ������2����ϸע��
int main() {
    // Merge Sort������ѧϰ�ĵ�һ��O(nlogn)���Ӷȵ��㷨
    // ������1��֮�����ɴ���100��������������
    // ע�⣺��Ҫ���׳���ʹ��SelectionSort, InsertionSort����BubbleSort����100�򼶵�����
    // ������ͼ�ʶ��O(n^2)���㷨��O(nlogn)�㷨�ı��ʲ��죺��
    int n = 50000;

    // ����1 һ���Բ���
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    // ����2 ���Խ������������
    // ���ڽ������������, ����Խ����, InsertionSort��ʱ������Խ������O(n)
    // ���Կ��Գ���, ��swapTimes�Ƚϴ�ʱ, MergeSort����
    // ���ǵ�swapTimesС��һ���̶�, InsertionSort��ñ�MergeSort��
    int swapTimes = 10;
    assert(swapTimes >= 0);

    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    system("pause");

    return 0;
}