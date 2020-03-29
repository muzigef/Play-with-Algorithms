#include <iostream>
#include "selectionSort.h"
#include "SortTestHelper.h"

using namespace std;

int main() {
    int num = 1000;
    int *arr = SortTestHelper::generateRandomArray(num, 0, 1000);
    SortTestHelper::testSort("selectionSort",selectionSort,arr, num);

    delete[] arr;

    system("pause");

    return 0;
}
