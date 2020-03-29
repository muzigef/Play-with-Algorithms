#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第三版Union-Find
namespace UF3 {
    class UnionFind {
    public:
        // 构造函数
        UnionFind(int n) {
            _count = n;
            _parent = new int[n];
            _size = new int[n];

            // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
            for (int i = 0; i < n; i++) {
                _parent[i] = i;
                _size[i] = 1;
            }
        }

        // 析构函数
        ~UnionFind() {
            delete[] _parent;
            delete[] _size;
        }

        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p) {
            assert(p >= 0 && p < _count);

            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while (p != _parent[p]) {
                p = _parent[p];
            }

            return p;
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot) {
                return;
            }

            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if (_size[pRoot] < _size[qRoot]) {
                _parent[pRoot] = qRoot;
                _size[qRoot] += _size[pRoot];  //维护_size数组
            }
            else {
                _parent[qRoot] = pRoot;
                _size[pRoot] += _size[qRoot];  //维护_size数组
            }
        }

    private:
        int* _parent; // _parent[i]表示第i个元素所指向的父节点
        int* _size;   // _size[i]表示以i为根的集合中元素个数
        int _count;   // 数据个数
    };
}