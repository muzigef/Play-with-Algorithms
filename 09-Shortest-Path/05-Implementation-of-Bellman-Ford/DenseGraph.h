#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

// ����ͼ - �ڽӾ���
template<typename Weight>
class DenseGraph {
public:
    DenseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
        _graphDate = vector<vector<Edge<Weight>*>>(n, vector<Edge<Weight>*>(n, nullptr));
    }

    ~DenseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        // �����v��w�Ѿ��б�, ɾ��������
        if (hasEdge(v, w)) {
            delete _graphDate[v][w];
            if (!_directed) {
                delete _graphDate[w][v];

                _edgeNum--;
            }
        }

        _graphDate[v][w] = new Edge<Weight>(v, w, weight);
        if (!_directed) {
            _graphDate[w][v] = new Edge<Weight>(w, v, weight);;
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        return _graphDate[v][w] != nullptr;
    }

    // ��ʾͼ����Ϣ
    void show() {
        for (int i = 0; i < _vertexNum; i++) {
            for (int j = 0; j < _vertexNum; j++)
                if (_graphDate[i][j]) {
                    cout << _graphDate[i][j]->weight() << "\t";
                }
                else {
                    cout << "NULL\t";
                }
                
            cout << endl;
        }
    }

private:
    int _vertexNum;    // �ڵ���
    int _edgeNum;    // ����
    bool _directed;  // �Ƿ�Ϊ����ͼ
    vector<vector<Edge<Weight>*>> _graphDate;  // ͼ�ľ�������,Ϊ�˱�ʾ�շ��㣬����Edgeָ��

public:
    // �ڱߵ�����, ����һ��ͼ��һ������,
    // ���������ͼ�к�����������������ж���
    class adjIterator {
    public:
        adjIterator(DenseGraph& graph, int v) :_graph(graph), _vertex(v), _index(-1) {

        }

        ~adjIterator() {

        }

        // ����ͼG���붥��v�����ӵĵ�һ������
        Edge<Weight>* begin() {
            // ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
            _index = -1;
            return next();
        }

        // ����ͼG���붥��v�����ӵ���һ������
        Edge<Weight>* next() {
            // �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��_graphDate[v][index]Ϊtrue
            for (_index += 1; _index < _graph.V(); _index++) {
                if (_graph._graphDate[_vertex][_index]) {
                    return _graph._graphDate[_vertex][_index];
                }
            }

            // ��û�ж����v������, �򷵻�nullptr
            return nullptr;
        }

        // �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
        bool end() {
            return _index >= _graph.V();
        }

    private:
        DenseGraph& _graph;  //���õ�ϡ��ͼ
        int _vertex;  //ͼ�Ķ���
        int _index;  //����
    };
};