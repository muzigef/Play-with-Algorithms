#pragma once

#include <iostream>
#include <cassert>
#include "IndexMinHeap.h"
#include "Edge.h"

using namespace std;

// 使用Prim算法求图的最小生成树
//时间复杂度为O(ElogV)
template<typename Graph, typename Weight>
class PrimMST {
public:
    // 构造函数, 使用Prim算法求图的最小生成树
    PrimMST(Graph& graph) :_graph(graph), _priorityQueue(IndexMinHeap<Weight>(_graph.V())) {
        assert(graph.E() >= 1);
        // 算法初始化
        _marked = new bool[_graph.V()];
        for (int i = 0; i < _graph.V(); i++) {
            _marked[i] = false;
            _edgeTo.push_back(nullptr);
        }
        _mst.clear();

        // Prim
        visit(0);
        while (!_priorityQueue.isEmpty()) {
            // 使用最小索引堆找出已经访问的边中权值最小的边
            // 最小索引堆中存储的是点的索引, 通过点的索引找到相对应的边
            int v = _priorityQueue.extractMinIndex();
            assert(_edgeTo[v]);
            _mst.push_back(*_edgeTo[v]);

            // 访问和这条边连接的还没有被访问过的节点
            visit(v);
        }

        // 计算最小生成树的权值
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~PrimMST() {
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

        // 将和节点v相连接的未访问的另一端点, 和与之相连接的边, 放入最小堆中
        typename Graph::adjIterator adj(_graph, v);
        for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
            int w = edge->other(v);
            if (!_marked[w]) {
                // 如果从没有考虑过这个端点, 直接将这个端点和与之相连接的边加入索引堆
                if (!_edgeTo[w]) {
                    _edgeTo[w] = edge;
                    _priorityQueue.insert(w, edge->weight());
                }
                // 如果曾经考虑这个端点, 但现在的边比之前考虑的边更短, 则进行替换
                else if (_edgeTo[w]->weight() > edge->weight()) {
                    _edgeTo[w] = edge;
                    _priorityQueue.change(w, edge->weight());
                }
            }
        }
    }


private:
    Graph& _graph; // 图的引用
    IndexMinHeap<Weight> _priorityQueue;  // 最小索引堆, 算法辅助数据结构
    vector<Edge<Weight>*> _edgeTo; // 访问的点所对应的边, 算法辅助数据结构
    bool* _marked;  // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> _mst;    // 最小生成树所包含的所有边
    Weight _mstWeight;             // 最小生成树的权值
};