#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第一版Union-Find
namespace UF1 {
    class UnionFind
    {
    public:
        //构造函数
        UnionFind(int n) {
            _count = n;
            _id = new int[n];

            // 初始化, 每一个id[i]指向自己, 没有合并的元素
            for (int i = 0; i < n; i++) {
                _id[i] = i;
            }
        }

        //析构函数
        ~UnionFind() {
            delete[] _id;
        }

        // 查找过程, 查找元素p所对应的集合编号
        int find(int p) {
            assert(p >= 0 && p < _count);
            return _id[p];
        }

        // 查看元素p和元素q是否所属一个集合
        // O(1)复杂度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(n) 复杂度
        void unionElements(int p, int q) {

            int pID = find(p);
            int qID = find(q);

            if (pID == qID)
                return;

            // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
            for (int i = 0; i < _count; i++)
                if (_id[i] == pID)
                    _id[i] = qID;
        }

    private:
        int* _id;   // 我们的第一版Union-Find本质就是一个数组
        int _count; // 数据个数
    };

}