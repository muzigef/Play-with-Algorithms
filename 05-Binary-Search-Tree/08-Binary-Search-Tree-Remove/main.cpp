#include "BinarySearchTree.h"
#include <ctime>

void shuffle(int arr[], int n) {

    srand(time(nullptr));
    for (int i = n - 1; i >= 0; i--) {
        int x = rand() % (i + 1);
        swap(arr[i], arr[x]);
    }
}

// 测试 remove
int main() {

    srand(time(NULL));
    BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

    // 取n个取值范围在[0...n)的随机整数放进二分搜索树中
    int n = 10000;
    for (int i = 0; i < n; i++) {
        int key = rand() % n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        bst.insert(key, value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // order数组中存放[0...n)的所有元素
    int* order=new int[n];
    for (int i = 0; i < n; i++)
        order[i] = i;
    // 打乱order数组的顺序
    shuffle(order, n);

    // 乱序删除[0...n)范围里的所有元素
    for (int i = 0; i < n; i++)
        if (bst.contain(order[i])) {
            bst.remove(order[i]);
            cout << "After remove " << order[i] << " size = " << bst.size() << endl;
        }

    // 最终整个二分搜索树应该为空
    cout << bst.size() << endl;

    system("pause");
    return 0;
}