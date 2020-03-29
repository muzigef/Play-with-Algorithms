#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {
public:
    // 构造函数, 求出无权图的联通分量
    Component(Graph& graph) :_graph(graph) {

        // 算法初始化
        _visited = new bool[graph.V()];
        _id = new int[graph.V()];
        _ccount = 0;

        for (int i = 0; i < graph.V(); i++) {
            _visited[i] = false;
            _id[i] = -1;
        }

        // 求图的联通分量
        for (int i = 0; i < graph.V(); i++) {
            if (!_visited[i]) {
                dfs(i);
                _ccount++;
            }
        }
    }

    ~Component() {
        delete[] _visited;
        delete[] _id;
    }

    // 返回图的联通分量个数
    int count() {
        return _ccount;
    }

    // 查询点v和点w是否联通
    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return _id[v] == _id[w];
    }

private:
    // 图的深度优先遍历
    void dfs(int v) {
        _visited[v] = true;
        _id[v] = _ccount;

        typename Graph::adjIterator adj(_graph, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!_visited[i]) {
                dfs(i);
            }
        }
    }

private:
    Graph& _graph;    // 图的引用
    bool* _visited;   // 记录dfs的过程中节点是否被访问
    int _ccount;      // 记录联通分量个数
    int* _id;         // 每个节点所对应的联通分量标记,并查集
};