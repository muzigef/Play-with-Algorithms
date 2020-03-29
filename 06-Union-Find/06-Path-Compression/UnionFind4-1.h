#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第四-1版Union-Find
namespace UF41 {
    class UnionFind {
    public:
        // 构造函数
        UnionFind(int n) {
            _count = n;
            _parent = new int[n];
            _size = new int[n];
            _rank = new int[n];

            // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
            for (int i = 0; i < n; i++) {
                _parent[i] = i;
                _size[i] = 1;
                _rank[i] = 1;
            }
        }

        // 析构函数
        ~UnionFind() {
            delete[] _parent;
            delete[] _size;
            delete[] _rank;
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

            // 根据两个元素所在树的层数数不同判断合并方向
            // 将层数少的集合合并到层数多的集合上
            if (_rank[pRoot] < _rank[qRoot]) {
                _parent[pRoot] = qRoot;
            }
            else if (_rank[pRoot] > _rank[qRoot]) {
                _parent[qRoot] = pRoot;
            }
            //如果层数相等，则选取元素少的往元素多的集合上合并，能够获取更优的并查集
            //但是增加判断条件，一般情况下在性能上可能并不会提升
            else {
                if (_size[pRoot] < _size[qRoot]) {
                    _parent[pRoot] = qRoot;
                    _size[qRoot] += _size[pRoot];
                    _rank[qRoot]++;  // 此时, 维护rank的值
                }
                else {
                    _parent[qRoot] = pRoot;
                    _size[pRoot] += _size[qRoot];
                    _rank[pRoot]++;  // 此时, 维护rank的值
                }
            }
        }

    private:
        int* _parent; // parent[i]表示第i个元素所指向的父节点
        int* _size;   // sz[i]表示以i为根的集合中元素个数
        int* _rank;   // rank[i]表示以i为根的集合所表示的树的层数
        int _count;   // 数据个数
    };
}