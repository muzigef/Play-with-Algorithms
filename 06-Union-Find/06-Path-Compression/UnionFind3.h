#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ�����Union-Find
namespace UF3 {
    class UnionFind {
    public:
        // ���캯��
        UnionFind(int n) {
            _count = n;
            _parent = new int[n];
            _size = new int[n];

            // ��ʼ��, ÿһ��parent[i]ָ���Լ�, ��ʾÿһ��Ԫ���Լ��Գ�һ������
            for (int i = 0; i < n; i++) {
                _parent[i] = i;
                _size[i] = 1;
            }
        }

        // ��������
        ~UnionFind() {
            delete[] _parent;
            delete[] _size;
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

            // ��������Ԫ����������Ԫ�ظ�����ͬ�жϺϲ�����
            // ��Ԫ�ظ����ٵļ��Ϻϲ���Ԫ�ظ�����ļ�����
            if (_size[pRoot] < _size[qRoot]) {
                _parent[pRoot] = qRoot;
                _size[qRoot] += _size[pRoot];  //ά��_size����
            }
            else {
                _parent[qRoot] = pRoot;
                _size[pRoot] += _size[qRoot];  //ά��_size����
            }
        }

    private:
        int* _parent; // _parent[i]��ʾ��i��Ԫ����ָ��ĸ��ڵ�
        int* _size;   // _size[i]��ʾ��iΪ���ļ�����Ԫ�ظ���
        int _count;   // ���ݸ���
    };
}