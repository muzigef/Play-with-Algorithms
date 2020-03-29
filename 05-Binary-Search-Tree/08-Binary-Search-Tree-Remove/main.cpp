#include "BinarySearchTree.h"
#include <ctime>

void shuffle(int arr[], int n) {

    srand(time(nullptr));
    for (int i = n - 1; i >= 0; i--) {
        int x = rand() % (i + 1);
        swap(arr[i], arr[x]);
    }
}

// ���� remove
int main() {

    srand(time(NULL));
    BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

    // ȡn��ȡֵ��Χ��[0...n)����������Ž�������������
    int n = 10000;
    for (int i = 0; i < n; i++) {
        int key = rand() % n;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        bst.insert(key, value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // order�����д��[0...n)������Ԫ��
    int* order=new int[n];
    for (int i = 0; i < n; i++)
        order[i] = i;
    // ����order�����˳��
    shuffle(order, n);

    // ����ɾ��[0...n)��Χ�������Ԫ��
    for (int i = 0; i < n; i++)
        if (bst.contain(order[i])) {
            bst.remove(order[i]);
            cout << "After remove " << order[i] << " size = " << bst.size() << endl;
        }

    // ������������������Ӧ��Ϊ��
    cout << bst.size() << endl;

    system("pause");
    return 0;
}