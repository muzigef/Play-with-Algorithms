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

public:
    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有顶点
    class adjIterator {
    public:
        adjIterator(DenseGraph& graph, int v) :_graph(graph), _vertex(v), _index(-1) {

        }

        ~adjIterator() {

        }

        // 返回图G中与顶点v相连接的第一个顶点
        int begin() {
            // 索引从-1开始, 因为每次遍历都需要调用一次next()
            _index = -1;
            return next();
        }

        // 返回图G中与顶点v相连接的下一个顶点
        int next() {
            // 从当前index开始向后搜索, 直到找到一个_graphDate[v][index]为true
            for (_index += 1; _index < _graph.V(); _index++) {
                if (_graph._graphDate[_vertex][_index]) {
                    return _index;
                }
            }

            // 若没有顶点和v相连接, 则返回-1
            return -1;
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        bool end() {
            return _index >= _graph.V();
        }

    private:
        DenseGraph& _graph;  //引用的稀疏图
        int _vertex;  //图的顶点
        int _index;  //索引
    };
};