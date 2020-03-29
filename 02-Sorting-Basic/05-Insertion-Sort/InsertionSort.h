#include <cassert>
#include <algorithm>

//插入排序对于基本有序的数据排序效率极高
template<typename T>
void insertionSort(T arr[], int n) {
    assert(n);
    for (int i = 1; i < n; i++) { //i从1开始循环，因为0是默认有序的
        //保证i在合适的位置，类似插位扑克牌
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            //swap是一种比较耗时的操作
            swap(arr[j], arr[j - 1]);
        }
    }
}