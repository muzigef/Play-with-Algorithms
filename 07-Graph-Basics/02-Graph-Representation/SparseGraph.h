#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // 初始化没有任何边
        _directed = directed;
        // _graphDate初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
        _graphDate = vector<vector<int>>(n, vector<int>());
    }

    ~SparseGraph() {

    }

    int V() { return _vertexNum; } // 返回节点个数
    int E() { return _edgeNum; } // 返回边的个数

    // 向图中添加一个边
    void addEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        //由于hasEdge()时间复杂度过高，一般情况下载稀疏图不会判断是否存在边(v,w),
        //所以该稀疏图中可能存在平行边，一般会在生成图之后批量处理平行边
        //v != w是为了防止自环边
        _graphDate[v].push_back(w);
        if (v != w && !_directed) {
            _graphDate[w].push_back(v);
        }

        _edgeNum++;
    }

    // 验证图中是否有从v到w的边
    // 在最差的情况下，该函数的时间复杂度为O(V),V:顶点个数
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
    int _vertexNum;    // 节点数
    int _edgeNum;    // 边数
    bool _directed;  // 是否为有向图
    vector<vector<int>> _graphDate;  // 图的具体数据
};