#pragma once

#include <iostream>
#include <ctime>
#include "UnionFind1.h"

using namespace std;

// 测试并查集的辅助函数
namespace UnionFindTestHelper {
    // 测试第一版本的并查集, 测试元素个数为n
    void testUF1(int n) {

        srand(time(nullptr));
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        // 进行n次操作, 每次随机选择两个元素进行合并操作
        //该步骤的事件复杂度为O(n^2)
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        //该步骤的事件复杂度为O(n)
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}