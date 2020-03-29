#include "MaxHeap.h"

using namespace std;

int main() {
    //模板类的实例化
    MaxHeap<int> maxheap(100);// = MaxHeap<int>(100);
    //或者MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;

    system("pause");
    return 0;
}