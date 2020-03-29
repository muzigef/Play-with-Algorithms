#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ�һ��Union-Find
namespace UF1 {
    class UnionFind
    {
    public:
        //���캯��
        UnionFind(int n) {
            _count = n;
            _id = new int[n];

            // ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
            for (int i = 0; i < n; i++) {
                _id[i] = i;
            }
        }

        //��������
        ~UnionFind() {
            delete[] _id;
        }

        // ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
        int find(int p) {
            assert(p >= 0 && p < _count);
            return _id[p];
        }

        // �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
        // O(1)���Ӷ�
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // �ϲ�Ԫ��p��Ԫ��q�����ļ���
        // O(n) ���Ӷ�
        void unionElements(int p, int q) {

            int pID = find(p);
            int qID = find(q);

            if (pID == qID)
                return;

            // �ϲ�������Ҫ����һ������Ԫ��, ������Ԫ�ص��������ϱ�źϲ�
            for (int i = 0; i < _count; i++)
                if (_id[i] == pID)
                    _id[i] = qID;
        }

    private:
        int* _id;   // ���ǵĵ�һ��Union-Find���ʾ���һ������
        int _count; // ���ݸ���
    };

}