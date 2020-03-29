#include "MaxHeap.h"

int main() {
    //模板类的实例化
    int n = 100;
    MaxHeap<int> maxheap(n);

    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        maxheap.insert(rand() % 100);
    }

    int* arr = new int[n];
    // 将maxheap中的数据逐渐使用extractMax取出来
    // 取出来的顺序应该是按照从大到小的顺序取出来的
    for (int i = 0; i < n; i++) {
        arr[i] = maxheap.extractMax();
        cout << arr[i] << " ";
    }
    cout << endl;

    // 确保arr数组是从大到小排列的
    for (int i = 1; i < n; i++)
        assert(arr[i - 1] >= arr[i]);

    delete[] arr;

    system("pause");
    return 0;
}