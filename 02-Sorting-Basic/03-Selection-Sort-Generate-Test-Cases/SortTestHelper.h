#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {
    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);

        int *arr = new int[n];

        //设置时间为随机种子
        srand(time(nullptr));
        for (int i = 0; i < n;i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // 打印arr数组的所有内容
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n ; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << endl;
    }
}