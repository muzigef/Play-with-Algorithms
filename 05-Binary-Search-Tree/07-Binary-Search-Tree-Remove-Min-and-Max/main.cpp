#include "BinarySearchTree.h"
#include <ctime>

// ���Զ����������е�removeMin��removeMax
int main() {

    srand(time(NULL));
    BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

    // ȡn��ȡֵ��Χ��[0...m)����������Ž�������������
    int n = 100;
    int m = 100;
    for (int i = 0; i < n; i++) {
        int key = rand() % m;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        //cout<<key<<" ";
        bst.insert(key, value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // ���� removeMin
    // �����Ԫ��Ӧ���Ǵ�С�������е�
    cout << "Test removeMin: " << endl;
    while (!bst.isEmpty()) {
        cout << "min: " << bst.minimum() << " , ";
        bst.removeMin();
        cout << "After removeMin, size = " << bst.size() << endl;
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        int key = rand() % n;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        //cout<<key<<" ";
        bst.insert(key, value);
    }
    // ע��, ����������ɵ��������ظ�, ����bst�е����������������С��n��

    // ���� removeMax
    // �����Ԫ��Ӧ���ǴӴ�С���е�
    cout << "Test removeMax: " << endl;
    while (!bst.isEmpty()) {
        cout << "max: " << bst.maximum() << " , ";
        bst.removeMax();
        cout << "After removeMax, size = " << bst.size() << endl;
    }

    system("pause");
    return 0;
}