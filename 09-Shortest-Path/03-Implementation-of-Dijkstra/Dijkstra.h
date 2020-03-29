#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include "IndexMinHeap.h"
#include "Edge.h"

using namespace std;

// Dijkstra�㷨�����·��
template<typename Graph, typename Weight>
class Dijkstra {
public:
    // ���캯��, ʹ��Dijkstra�㷨�����·��
    Dijkstra(Graph& graph, int source) :_graph(graph) {
        // �㷨��ʼ��
        assert(source >= 0 && source < _graph.V());
        _source = source;
        _marked = new bool[_graph.V()];
        _distTo = new int[_graph.V()];

        for (int i = 0; i < graph.V(); i++) {
            _marked[i] = false;
            _distTo[i] = Weight();
            _from.push_back(nullptr);
        }

        // ʹ�������Ѽ�¼��ǰ�ҵ��ĵ���ÿ���������̾���
        IndexMinHeap<Weight> priorityQueue(_graph.V());

        // ������ʵ��_source���г�ʼ��
        _distTo[_source] = Weight();
        _marked[_source] = true;
        // ��������from[s]��������new������, ע��Ҫ������������delete��
        _from[_source] = new Edge<Weight>(_source, _source, Weight());
        priorityQueue.insert(_source, _distTo[_source]);

        while (!priorityQueue.isEmpty()) {
            int v = priorityQueue.extractMinIndex();
            _marked[v] = true;

            // ��v���������ڽڵ���и���
            typename Graph::adjIterator adj(_graph, v);
            for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                int w = edge->other(v);
                // �����v�㵽w������·���Ѿ��ҵ��������
                if (_marked[w]) {
                    continue;
                }

                // �����v�㵽w������·����û���ҵ�
                // ���w����ǰû�з��ʹ�
                if (!_from[w]) {
                    _distTo[w] = _distTo[v] + edge->weight();
                    _from[w] = edge;
                    priorityQueue.insert(w, _distTo[w]);
                }
                // ���߷��ʹ�, ����ͨ����ǰ��v�㵽w��������, ����и���
                else if (_distTo[v] + edge->weight() < _distTo[w]) {
                    _distTo[w] = _distTo[v] + edge->weight();
                    _from[w] = edge;
                    priorityQueue.change(w, _distTo[w]);
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] _marked;
        delete[] _distTo;
        delete _from[_source];
    }

    // ���ش�s�㵽w������·������
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        assert(hasPathTo(w));
        return _distTo[w];
    }

    // �жϴ�s�㵽w���Ƿ���ͨ
    bool hasPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        return _marked[w];
    }

    // Ѱ�Ҵ�_source��w�����·��, ������·�������ıߴ����vec��
    void shortestPath(int w, vector<Edge<Weight>> &vec) {

        assert(w >= 0 && w < _graph.V());
        assert(hasPathTo(w));

        // ͨ��from����������ҵ���_source��w��·��, ��ŵ�ջ��
        stack<Edge<Weight>*> s;
        Edge<Weight> *edge = _from[w];
        while (edge->V() != _source) {
            s.push(edge);
            edge = _from[edge->V()];
        }
        s.push(edge);

        // ��ջ������ȡ��Ԫ��, ���˳��Ĵ�_source��w��·��
        while (!s.empty()) {
            edge = s.top();
            vec.push_back(*edge);
            s.pop();
        }
    }

    // ��ӡ����_source�㵽w���·��
    void showPath(int w) {

        assert(w >= 0 && w < _graph.V());
        assert(hasPathTo(w));

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].V() << " -> ";
            if (i == vec.size() - 1)
                cout << vec[i].W() << endl;
        }
    }

private:
    Graph& _graph;   // ͼ������
    int _source;  // ��ʼ��
    vector<Edge<Weight>*> _from;  // _from[i]��¼���·����, ����i��ı�����һ��
    Weight* _distTo;  // _distTo[i]�洢����ʼ��s��i�����·������
    bool* _marked;  // �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
};