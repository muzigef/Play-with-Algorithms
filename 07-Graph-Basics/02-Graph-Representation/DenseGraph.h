#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// ����ͼ - �ڽӾ���
class DenseGraph {
public:
    DenseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
        _graphDate = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    ~DenseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        if (hasEdge(v, w)) {
            return;
        }

        _graphDate[v][w] = true;
        if (!_directed) {
            _graphDate[w][v] = true;
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        return _graphDate[v][w];
    }

private:
    int _vertexNum;    // �ڵ���
    int _edgeNum;    // ����
    bool _directed;  // �Ƿ�Ϊ����ͼ
    vector<vector<bool>> _graphDate;  // ͼ�ľ�������
};