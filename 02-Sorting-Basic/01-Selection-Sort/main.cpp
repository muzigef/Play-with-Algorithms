#include <iostream>
#include "selectionSort.h"

using namespace std;

int main() {
    int arr[] = { 4, 1, 6, 3, 7, 2, 8 };
    selectionSort(arr, 7);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
