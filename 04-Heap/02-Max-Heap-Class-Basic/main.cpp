#include "MaxHeap.h"

using namespace std;

int main() {
    //ģ�����ʵ����
    MaxHeap<int> maxheap(100);// = MaxHeap<int>(100);
    //����MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;

    system("pause");
    return 0;
}