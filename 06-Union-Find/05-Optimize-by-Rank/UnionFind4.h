#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ��İ�Union-Find
namespace UF4 {
    class UnionFind {
    public:
        // ���캯��
        UnionFind(int n) {
            _count = n;
            _parent = new int[n];
            _rank = new int[n];

            // ��ʼ��, ÿһ��parent[i]ָ���Լ�, ��ʾÿһ��Ԫ���Լ��Գ�һ������
            for (int i = 0; i < n; i++) {
                _parent[i] = i;
                _rank[i] = 1;
            }
        }

        // ��������
        ~UnionFind() {
            delete[] _parent;
            delete[] _rank;
        }

        // ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
        // O(h)���Ӷ�, hΪ���ĸ߶�
        int find(int p) {
            assert(p >= 0 && p < _count);

            // ����ȥ��ѯ�Լ��ĸ��׽ڵ�, ֱ��������ڵ�
            // ���ڵ���ص�: parent[p] == p
            while (p != _parent[p]) {
                p = _parent[p];
            }

            return p;
        }

        // �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
        // O(h)���Ӷ�, hΪ���ĸ߶�
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // �ϲ�Ԫ��p��Ԫ��q�����ļ���
        // O(h)���Ӷ�, hΪ���ĸ߶�
        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot) {
                return;
            }

            // ��������Ԫ���������Ĳ�������ͬ�жϺϲ�����
            // �������ٵļ��Ϻϲ���������ļ�����
            if (_rank[pRoot] < _rank[qRoot]) {
                _parent[pRoot] = qRoot;
            }
            else if (_rank[pRoot] > _rank[qRoot]) {
                _parent[qRoot] = pRoot;
            }
            else {
                _parent[pRoot] = qRoot;
                _rank[qRoot]++;  // ��ʱ, ά��rank��ֵ
            }
        }

    private:
        int* _parent; // parent[i]��ʾ��i��Ԫ����ָ��ĸ��ڵ�
        int* _rank;   // rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
        int _count;   // ���ݸ���
    };
}