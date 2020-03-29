#include "BinarySearchTree.h"
#include <ctime>

// 测试二分搜索树的前中后序遍历
int main() {

    srand(time(NULL));
    BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for (int i = 0; i < N; i++) {
        int key = rand() % M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    cout << endl;

    // 测试二分搜索树的size()
    cout << "size: " << bst.size() << endl << endl;

    // 测试二分搜索树的前序遍历 preOrder
    cout << "preOrder: " << endl;
    bst.preOrder();
    cout << endl;

    // 测试二分搜索树的中序遍历 inOrder
    cout << "inOrder: " << endl;
    bst.inOrder();
    cout << endl;

    // 测试二分搜索树的后序遍历 postOrder
    cout << "postOrder: " << endl;
    bst.postOrder();
    cout << endl;

    // 测试二分搜索树的层序遍历 levelOrder
    cout << "levelOrder: " << endl;
    bst.levelOrder();
    cout << endl;

    system("pause");
    return 0;
}