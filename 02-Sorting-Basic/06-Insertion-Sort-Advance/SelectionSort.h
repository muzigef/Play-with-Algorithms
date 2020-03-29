#include <cassert>
#include <algorithm>

template<typename T>
void selectionSort(T arr[], int n) {
    assert(n);
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //swap��һ�ֱȽϺ�ʱ�Ĳ���
        swap(arr[i], arr[minIndex]);
    }
}