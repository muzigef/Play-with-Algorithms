#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// Dijkstra�㷨�����·��
template<typename Graph, typename Weight>
class BellmanFord {
public:
    // ���캯��, ʹ��Dijkstra�㷨�����·��
    BellmanFord(Graph& graph, int source) :_graph(graph) {
        // �㷨��ʼ��
        assert(source >= 0 && source < _graph.V());
        _source = source;
        _distTo = new int[_graph.V()];

        for (int i = 0; i < graph.V(); i++) {
            _distTo[i] = Weight();
            _from.push_back(nullptr);
        }


        // ������ʵ��_source���г�ʼ��
        // ����distTo[s] = 0, ������from[s]��Ϊnullptr, ��ʾ��ʼs�ڵ�ɴ��Ҿ���Ϊ0
        _distTo[_source] = Weight();
        // ��������from[s]��������new������, ע��Ҫ������������delete��
        _from[_source] = new Edge<Weight>(_source, _source, Weight());

        // Bellman-Ford�Ĺ���
        // ����V-1��ѭ��, ÿһ��ѭ���������㵽�������е�, ���ʹ��pass���ɵ������̾���
        for (int pass = 1; pass < _graph.V(); pass++) {
            // ÿ��ѭ���ж����еı߽���һ���ɳڲ���
            // �������бߵķ�ʽ���ȱ������еĶ���, Ȼ����������ж������ڵ����б�
            for (int v = 0; v < _graph.V(); v++) {
                // ʹ������ʵ�ֵ��ڱߵ��������������ж������ڵ����б�
                typename Graph::adjIterator adj(_graph, v);
                for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                    int w = edge->other(v);
                    // ����ÿһ���������ж�e->v()�ɴ�
                    // ֮�����e->w()��ǰû�е������ ��Ȼ���ǿ��Ը���distTo[e->w()]
                    // ����e->w()��ǰ��Ȼ�����, ����ͨ�����e���ǿ��Ի��һ�����̵ľ���, �����Խ���һ���ɳڲ���, ����Ҳ���Ը���distTo[e->w()]
                    if(_from[v] && (_from[w] == nullptr || _distTo[v] + edge->weight() < _distTo[w])) {
                        _distTo[w] = _distTo[v] + edge->weight();
                        _from[w] = edge;
                    }
                }
            }
        }

        _hasNegativeCycle = detectNegativeCycle();
    }

    ~BellmanFord() {
        delete[] _distTo;
        delete _from[_source];
    }

    // ����ͼ���Ƿ��и�Ȩ��
    bool negativeCycle() {
        return _hasNegativeCycle;
    }

    // ���ش�s�㵽w������·������
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        assert(!_hasNegativeCycle);
        assert(hasPathTo(w));
        return _distTo[w];
    }

    // �жϴ�s�㵽w���Ƿ���ͨ
    bool hasPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        return _from[w] != nullptr;
    }

    // Ѱ�Ҵ�_source��w�����·��, ������·�������ıߴ����vec��
    void shortestPath(int w, vector<Edge<Weight>> &vec) {
        assert(w >= 0 && w < _graph.V());
        assert(!_hasNegativeCycle);
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
        assert(!_hasNegativeCycle);
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
    // �ж�ͼ���Ƿ��и�Ȩ��
    bool detectNegativeCycle() {

        //��V��������V-1���ɳڲ���
        for (int pass = 1; pass < _graph.V(); pass++) {
            //����V������
            for (int v = 0; v < _graph.V(); v++) {
                typename Graph::adjIterator adj(_graph, v);
                for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                    int w = edge->other(v);
                    if (_from[v] && (_from[w] == nullptr || _distTo[v] + edge->weight() < _distTo[w])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    Graph& _graph;   // ͼ������
    int _source;  // ��ʼ��
    vector<Edge<Weight>*> _from;  // _from[i]��¼���·����, ����i��ı�����һ��
    Weight* _distTo;  // _distTo[i]�洢����ʼ��s��i�����·������
    bool _hasNegativeCycle;      // ���ͼ���Ƿ��и�Ȩ��
};