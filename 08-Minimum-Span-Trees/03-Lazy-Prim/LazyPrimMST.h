#pragma once

#include <iostream>
#include <cassert>
#include "MinHeap.h"
#include "Edge.h"

using namespace std;

// ʹ��Prim�㷨��ͼ����С������
//ʱ�临�Ӷ�ΪO(ElogE)
template<typename Graph, typename Weight>
class LazyPrimMST {
public:
    // ���캯��, ʹ��Prim�㷨��ͼ����С������
    LazyPrimMST(Graph& graph) :_graph(graph), _priorityQueue(MinHeap<Edge<Weight>>(_graph.E())) {
        // �㷨��ʼ��
        _marked = new bool[_graph.V()];
        for (int i = 0; i < _graph.V(); i++) {
            _marked[i] = false;
        }
        _mst.clear();

        // Lazy Prim
        visit(0);
        while (!_priorityQueue.isEmpty()) {
            // ʹ����С���ҳ��Ѿ����ʵı���Ȩֵ��С�ı�
            Edge<Weight> edge = _priorityQueue.extractMin();

            // ��������ߵ����˶��Ѿ����ʹ���, ���ӵ�������
            if (_marked[edge.V()] == _marked[edge.W()]) {
                continue;
            }

            // ����, ��������Ӧ�ô�������С��������
            _mst.push_back(edge);

            // ���ʺ����������ӵĻ�û�б����ʹ��Ľڵ�
            if (!_marked[edge.V()]) {
                visit(edge.V());
            }
            else {
                visit(edge.W());
            }
        }

        // ������С��������Ȩֵ
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~LazyPrimMST() {
        delete[] _marked;
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
    void visit(int v) {
        assert(!_marked[v]);
        _marked[v] = true;

        // ���ͽڵ�v�����ӵ�����δ���ʵı߷�����С����
        typename Graph::adjIterator adj(_graph, v);
        for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
            if (!_marked[edge->other(v)]) {
                _priorityQueue.insert(*edge);
            }
        }
    }


private:
    Graph& _graph; // ͼ������
    MinHeap<Edge<Weight>> _priorityQueue;  // ��С��, �㷨�������ݽṹ
    bool* _marked;  // �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
    vector<Edge<Weight>> _mst;    // ��С�����������������б�
    Weight _mstWeight;             // ��С��������Ȩֵ
};