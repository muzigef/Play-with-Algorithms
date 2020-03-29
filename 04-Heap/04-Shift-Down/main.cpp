#include "MaxHeap.h"

int main() {
    //ģ�����ʵ����
    int n = 100;
    MaxHeap<int> maxheap(n);

    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        maxheap.insert(rand() % 100);
    }

    int* arr = new int[n];
    // ��maxheap�е�������ʹ��extractMaxȡ����
    // ȡ������˳��Ӧ���ǰ��մӴ�С��˳��ȡ������
    for (int i = 0; i < n; i++) {
        arr[i] = maxheap.extractMax();
        cout << arr[i] << " ";
    }
    cout << endl;

    // ȷ��arr�����ǴӴ�С���е�
    for (int i = 1; i < n; i++)
        assert(arr[i - 1] >= arr[i]);

    delete[] arr;

    system("pause");
    return 0;
}