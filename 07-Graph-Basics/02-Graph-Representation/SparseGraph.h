#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// ϡ��ͼ - �ڽӱ�
class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
        _graphDate = vector<vector<int>>(n, vector<int>());
    }

    ~SparseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        //����hasEdge()ʱ�临�Ӷȹ��ߣ�һ���������ϡ��ͼ�����ж��Ƿ���ڱ�(v,w),
        //���Ը�ϡ��ͼ�п��ܴ���ƽ�бߣ�һ���������ͼ֮����������ƽ�б�
        //v != w��Ϊ�˷�ֹ�Ի���
        _graphDate[v].push_back(w);
        if (v != w && !_directed) {
            _graphDate[w].push_back(v);
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    // ����������£��ú�����ʱ�临�Ӷ�ΪO(V),V:�������
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        for (int i = 0; i < _graphDate[v].size(); i++) {
            if (_graphDate[v][i] == w) {
                return true;
            }
        }

        return false;
    }

private:
    int _vertexNum;    // �ڵ���
    int _edgeNum;    // ����
    bool _directed;  // �Ƿ�Ϊ����ͼ
    vector<vector<int>> _graphDate;  // ͼ�ľ�������
};