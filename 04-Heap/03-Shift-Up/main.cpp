#include "MaxHeap.h"

int main() {
    //模板类的实例化
    MaxHeap<int> maxheap(100);// = MaxHeap<int>(100);
    //MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;

    srand(time(nullptr));
    for (int i = 0; i < 15; i++) {
        maxheap.insert(rand() % 100);
    }

    maxheap.testPrint();

    system("pause");
    return 0;
}