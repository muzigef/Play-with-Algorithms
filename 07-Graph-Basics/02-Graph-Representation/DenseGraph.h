#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph {
public:
    DenseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // 初始化没有任何边
        _directed = directed;
        // _graphDate初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
        _graphDate = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    ~DenseGraph() {

    }

    int V() { return _vertexNum; } // 返回节点个数
    int E() { return _edgeNum; } // 返回边的个数

    // 向图中添加一个边
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

    // 验证图中是否有从v到w的边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        return _graphDate[v][w];
    }

private:
    int _vertexNum;    // 节点数
    int _edgeNum;    // 边数
    bool _directed;  // 是否为有向图
    vector<vector<bool>> _graphDate;  // 图的具体数据
};