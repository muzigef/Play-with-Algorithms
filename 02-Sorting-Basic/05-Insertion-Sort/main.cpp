#include <iostream>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "SortTestHelper.h"

using namespace std;

int main() {
    int num = 1000;
    int *arr1 = SortTestHelper::generateRandomArray(num, 0, 1000);
    int *arr2 = SortTestHelper::copyIntArray(arr1,num);

    SortTestHelper::testSort("SelectionSort", selectionSort, arr1, num);
    SortTestHelper::testSort("InsertionSort", insertionSort, arr2, num);

    delete[] arr1;
    delete[] arr2;

    system("pause");

    return 0;
}
