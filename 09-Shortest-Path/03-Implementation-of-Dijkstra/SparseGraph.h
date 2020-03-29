#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

// 稀疏图 - 邻接表
template<typename Weight>
class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // 初始化没有任何边
        _directed = directed;
        // _graphDate初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任何边
        _graphDate = vector<vector<Edge<Weight>*>>(n, vector<Edge<Weight>*>());
    }

    ~SparseGraph() {

    }

    int V() { return _vertexNum; } // 返回节点个数
    int E() { return _edgeNum; } // 返回边的个数

    // 向图中添加一个边
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        //由于hasEdge()时间复杂度过高，一般情况下载稀疏图不会判断是否存在边(v,w),
        //所以该稀疏图中可能存在平行边，一般会在生成图之后批量处理平行边
        //v != w是为了防止自环边
        _graphDate[v].push_back(new Edge<Weight>(v, w, weight));
        if (v != w && !_directed) {
            _graphDate[w].push_back(new Edge<Weight>(w, v, weight));
        }

        _edgeNum++;
    }

    // 验证图中是否有从v到w的边
    // 在最差的情况下，该函数的时间复杂度为O(V),V:顶点个数
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        for (int i = 0; i < _graphDate[v].size(); i++) {
            if (_graphDate[v][i]->other(v) == w) {
                return true;
            }
        }

        return false;
    }

    // 显示图的信息
    void show() {

        for (int i = 0; i < _vertexNum; i++) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < _graphDate[i].size(); j++)
                cout << "( to:" << _graphDate[i][j]->W() << ",wt:" << _graphDate[i][j]->weight() << ")\t";
            cout << endl;
        }
    }

private:
    int _vertexNum;    // 节点数
    int _edgeNum;    // 边数
    bool _directed;  // 是否为有向图
    vector<vector<Edge<Weight>*>> _graphDate;  // 图的具体数据,为了表示空方便，采用Edge指针

public:
    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有顶点
    class adjIterator {
    public:
        adjIterator(SparseGraph& graph, int v) :_graph(graph), _vertex(v),_index(0) {

        }

        ~adjIterator() {

        }

        // 返回图G中与顶点v相连接的第一个顶点
        Edge<Weight>* begin() {
            _index = 0;
            if (_graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][0];
            }

            // 若没有顶点和v相连接, 则返回nullptr
            return nullptr;
        }

        // 返回图G中与顶点v相连接的下一个顶点
        Edge<Weight>* next() {
            _index++;

            if (_index < _graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][_index];
            }

            // 若没有顶点和v相连接, 则返回nullptr
            return nullptr;
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        bool end() {
            return _index >= _graph._graphDate[_vertex].size();
        }

    private:
        SparseGraph& _graph;  //引用的稀疏图
        int _vertex;  //图的顶点
        int _index;  //索引
    };
};