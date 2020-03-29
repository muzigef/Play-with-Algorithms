#include "Student.h"
#include "selectionSort.h"

int main() {
    Student arr[4] = { { "D", 90 }, { "C", 100 }, { "B", 95 }, { "A", 95 } };
    selectionSort(arr, 4);

    for (int i = 0; i < 4; i++) {
        cout << arr[i];
    }
    cout << endl;

    system("pause");

    return 0;
}
