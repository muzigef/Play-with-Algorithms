#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"

using namespace std;


// �Ƚ�Merge Sort��Quick Sort���������㷨������Ч��
// ���������㷨��Ȼ����O(nlogn)�����, ����Quick Sort�㷨�г�����������
// Quick SortҪ��Merge Sort��, ��ʹ���Ƕ�Merge Sort�������Ż�
int main() {

    int n = 1000000;

    // ����1 һ���Բ���
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


    // ����2 ���Խ������������
    // ���Ƕ��ڽ������������, ���ǵĿ��������㷨�˻�����O(n^2)������㷨
    // ˼��һ��Ϊʲô���ڽ������������, �����˻�����O(n^2)���㷨? :)
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

        // ����3 ���Դ��ڰ���������ͬԪ�ص�����
        // ����ʱ, ���ں��д�����ͬԪ�ص�����, ���ǵĿ��������㷨�ٴ��˻�����O(n^2)������㷨
        // ˼��һ��Ϊʲô�����������, �����˻�����O(n^2)���㷨? :)
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
