#pragma once

#include <iostream>
#include <cassert>
#include "IndexMinHeap.h"
#include "Edge.h"

using namespace std;

// ʹ��Prim�㷨��ͼ����С������
//ʱ�临�Ӷ�ΪO(ElogV)
template<typename Graph, typename Weight>
class PrimMST {
public:
    // ���캯��, ʹ��Prim�㷨��ͼ����С������
    PrimMST(Graph& graph) :_graph(graph), _priorityQueue(IndexMinHeap<Weight>(_graph.V())) {
        assert(graph.E() >= 1);
        // �㷨��ʼ��
        _marked = new bool[_graph.V()];
        for (int i = 0; i < _graph.V(); i++) {
            _marked[i] = false;
            _edgeTo.push_back(nullptr);
        }
        _mst.clear();

        // Prim
        visit(0);
        while (!_priorityQueue.isEmpty()) {
            // ʹ����С�������ҳ��Ѿ����ʵı���Ȩֵ��С�ı�
            // ��С�������д洢���ǵ������, ͨ����������ҵ����Ӧ�ı�
            int v = _priorityQueue.extractMinIndex();
            assert(_edgeTo[v]);
            _mst.push_back(*_edgeTo[v]);

            // ���ʺ����������ӵĻ�û�б����ʹ��Ľڵ�
            visit(v);
        }

        // ������С��������Ȩֵ
        _mstWeight = _mst[0].weight();
        for (int i = 1; i < _mst.size(); i++) {
            _mstWeight += _mst[i].weight();
        }
    }

    ~PrimMST() {
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

        // ���ͽڵ�v�����ӵ�δ���ʵ���һ�˵�, ����֮�����ӵı�, ������С����
        typename Graph::adjIterator adj(_graph, v);
        for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
            int w = edge->other(v);
            if (!_marked[w]) {
                // �����û�п��ǹ�����˵�, ֱ�ӽ�����˵����֮�����ӵı߼���������
                if (!_edgeTo[w]) {
                    _edgeTo[w] = edge;
                    _priorityQueue.insert(w, edge->weight());
                }
                // ���������������˵�, �����ڵı߱�֮ǰ���ǵı߸���, ������滻
                else if (_edgeTo[w]->weight() > edge->weight()) {
                    _edgeTo[w] = edge;
                    _priorityQueue.change(w, edge->weight());
                }
            }
        }
    }


private:
    Graph& _graph; // ͼ������
    IndexMinHeap<Weight> _priorityQueue;  // ��С������, �㷨�������ݽṹ
    vector<Edge<Weight>*> _edgeTo; // ���ʵĵ�����Ӧ�ı�, �㷨�������ݽṹ
    bool* _marked;  // �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
    vector<Edge<Weight>> _mst;    // ��С�����������������б�
    Weight _mstWeight;             // ��С��������Ȩֵ
};