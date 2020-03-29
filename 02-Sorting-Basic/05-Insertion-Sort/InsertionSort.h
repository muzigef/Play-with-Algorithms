#include <cassert>
#include <algorithm>

//����������ڻ����������������Ч�ʼ���
template<typename T>
void insertionSort(T arr[], int n) {
    assert(n);
    for (int i = 1; i < n; i++) { //i��1��ʼѭ������Ϊ0��Ĭ�������
        //��֤i�ں��ʵ�λ�ã����Ʋ�λ�˿���
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            //swap��һ�ֱȽϺ�ʱ�Ĳ���
            swap(arr[j], arr[j - 1]);
        }
    }
}