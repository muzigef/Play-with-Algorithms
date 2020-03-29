#include "BinarySearchTree.h"
#include <ctime>

// ���Զ�����������ǰ�к������
int main() {

    srand(time(NULL));
    BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

    // ȡn��ȡֵ��Χ��[0...m)����������Ž�������������
    int N = 10;
    int M = 100;
    for (int i = 0; i < N; i++) {
        int key = rand() % M;
        // Ϊ�˺������Է���,����valueֵȡ��keyֵһ��
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    cout << endl;

    // ���Զ�����������size()
    cout << "size: " << bst.size() << endl << endl;

    // ���Զ�����������ǰ����� preOrder
    cout << "preOrder: " << endl;
    bst.preOrder();
    cout << endl;

    // ���Զ������������������ inOrder
    cout << "inOrder: " << endl;
    bst.inOrder();
    cout << endl;

    // ���Զ����������ĺ������ postOrder
    cout << "postOrder: " << endl;
    bst.postOrder();
    cout << endl;

    // ���Զ����������Ĳ������ levelOrder
    cout << "levelOrder: " << endl;
    bst.levelOrder();
    cout << endl;

    system("pause");
    return 0;
}