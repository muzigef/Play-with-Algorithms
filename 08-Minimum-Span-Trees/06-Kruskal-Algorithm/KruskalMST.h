#pragma once

#include <iostream>
#include "UnionFind.h"
#include "MinHeap.h"

// ʹ��Kruskal�㷨��ͼ����С������
//ʱ�临�Ӷ�ΪO(ElogE),һ�������E>V������ʱ�临�Ӷȱ�Prim�㷨�ߣ�������LazyPrim�ͻ�Ҫ��һЩ��
//����Kruskal�㷨˼��򵥣���һЩСͼ�л��ǿ���ʹ�õ�
template<typename Graph, typename Weight>
class KruskalMST {
public:
    // ���캯��, ʹ��Kruskal�㷨����graph����С������
    KruskalMST(Graph& graph) {

        // ��С��, �㷨�������ݽṹ,��ͼ�е����бߴ�ŵ�һ����С����
        MinHeap<Edge<Weight>> priorityQueue(graph.E());
        for (int i = 0; i < graph.V(); i++) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                //��ֹ����ͼ�����߾�������С��
                if (edge->V() < edge->W()) {
                    priorityQueue.insert(*edge);
                }
            }
        }

        //����һ�����鼯,���鿴�Ѿ����ʵĽڵ����ͨ������������ж��Ƿ���ڻ�, 
        UF5::UnionFind unionFind(graph.V());
        while (!priorityQueue.isEmpty() && _mst.size() < graph.V() - 1) {
            // ����С�������δ�С����ȡ�����еı�
            Edge<Weight> edge = priorityQueue.extractMin();

            // ����ñߵ������˵�����ͨ��, ˵�����������߽�������, �ӵ�������
            if (unionFind.isConnected(edge.V(), edge.W())) {
                continue;
            }

            // ����, ����������ӽ���С������, ͬʱ��Ǳߵ������˵���ͨ
            _mst.push_back(edge);
            unionFind.unionElements(edge.V(), edge.W());
        }

        // ������С��������Ȩֵ
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~KruskalMST() {

    }

    // ������С�����������б�
    vector<Edge<Weight>> mstEdges() {
        return _mst;
    };

    // ������С��������Ȩֵ
    Weight result() {
        return _mstWeight;
    };

private:
    vector<Edge<Weight>> _mst;    // ��С�����������������б�
    Weight _mstWeight;             // ��С��������Ȩֵ
};