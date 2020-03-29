#pragma once

#include <iostream>
#include <cassert>
#include "MinHeap.h"
#include "Edge.h"

using namespace std;

// 使用Prim算法求图的最小生成树
//时间复杂度为O(ElogE)
template<typename Graph, typename Weight>
class LazyPrimMST {
public:
    // 构造函数, 使用Prim算法求图的最小生成树
    LazyPrimMST(Graph& graph) :_graph(graph), _priorityQueue(MinHeap<Edge<Weight>>(_graph.E())) {
        // 算法初始化
        _marked = new bool[_graph.V()];
        for (int i = 0; i < _graph.V(); i++) {
            _marked[i] = false;
        }
        _mst.clear();

        // Lazy Prim
        visit(0);
        while (!_priorityQueue.isEmpty()) {
            // 使用最小堆找出已经访问的边中权值最小的边
            Edge<Weight> edge = _priorityQueue.extractMin();

            // 如果这条边的两端都已经访问过了, 则扔掉这条边
            if (_marked[edge.V()] == _marked[edge.W()]) {
                continue;
            }

            // 否则, 这条边则应该存在在最小生成树中
            _mst.push_back(edge);

            // 访问和这条边连接的还没有被访问过的节点
            if (!_marked[edge.V()]) {
                visit(edge.V());
            }
            else {
                visit(edge.W());
            }
        }

        // 计算最小生成树的权值
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~LazyPrimMST() {
        delete[] _marked;
    }

    // 返回最小生成树的所有边
    vector<Edge<Weight>> mstEdges() {
        return _mst;
    };

    // 返回最小生成树的权值
    Weight result() {
        return _mstWeight;
    };

private:
    void visit(int v) {
        assert(!_marked[v]);
        _marked[v] = true;

        // 将和节点v相连接的所有未访问的边放入最小堆中
        typename Graph::adjIterator adj(_graph, v);
        for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
            if (!_marked[edge->other(v)]) {
                _priorityQueue.insert(*edge);
            }
        }
    }


private:
    Graph& _graph; // 图的引用
    MinHeap<Edge<Weight>> _priorityQueue;  // 最小堆, 算法辅助数据结构
    bool* _marked;  // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> _mst;    // 最小生成树所包含的所有边
    Weight _mstWeight;             // 最小生成树的权值
};