#pragma once

#include <iostream>
#include "UnionFind.h"
#include "MinHeap.h"

// 使用Kruskal算法求图的最小生成树
//时间复杂度为O(ElogE),一般情况下E>V，所以时间复杂度比Prim算法高，甚至比LazyPrim和还要高一些，
//但是Kruskal算法思想简单，在一些小图中还是可以使用的
template<typename Graph, typename Weight>
class KruskalMST {
public:
    // 构造函数, 使用Kruskal算法计算graph的最小生成树
    KruskalMST(Graph& graph) {

        // 最小堆, 算法辅助数据结构,将图中的所有边存放到一个最小堆中
        MinHeap<Edge<Weight>> priorityQueue(graph.E());
        for (int i = 0; i < graph.V(); i++) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                //防止无向图两条边均加入最小堆
                if (edge->V() < edge->W()) {
                    priorityQueue.insert(*edge);
                }
            }
        }

        //创建一个并查集,来查看已经访问的节点的联通情况，即用于判断是否存在环, 
        UF5::UnionFind unionFind(graph.V());
        while (!priorityQueue.isEmpty() && _mst.size() < graph.V() - 1) {
            // 从最小堆中依次从小到大取出所有的边
            Edge<Weight> edge = priorityQueue.extractMin();

            // 如果该边的两个端点是联通的, 说明加入这条边将产生环, 扔掉这条边
            if (unionFind.isConnected(edge.V(), edge.W())) {
                continue;
            }

            // 否则, 将这条边添加进最小生成树, 同时标记边的两个端点联通
            _mst.push_back(edge);
            unionFind.unionElements(edge.V(), edge.W());
        }

        // 计算最小生成树的权值
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~KruskalMST() {

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
    vector<Edge<Weight>> _mst;    // 最小生成树所包含的所有边
    Weight _mstWeight;             // 最小生成树的权值
};