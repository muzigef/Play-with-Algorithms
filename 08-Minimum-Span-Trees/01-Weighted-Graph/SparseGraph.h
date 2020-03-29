#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

// ϡ��ͼ - �ڽӱ�
template<typename Weight>
class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κα�
        _graphDate = vector<vector<Edge<Weight>*>>(n, vector<Edge<Weight>*>());
    }

    ~SparseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        //����hasEdge()ʱ�临�Ӷȹ��ߣ�һ���������ϡ��ͼ�����ж��Ƿ���ڱ�(v,w),
        //���Ը�ϡ��ͼ�п��ܴ���ƽ�бߣ�һ���������ͼ֮����������ƽ�б�
        //v != w��Ϊ�˷�ֹ�Ի���
        _graphDate[v].push_back(new Edge<Weight>(v, w, weight));
        if (v != w && !_directed) {
            _graphDate[w].push_back(new Edge<Weight>(w, v, weight));
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    // ����������£��ú�����ʱ�临�Ӷ�ΪO(V),V:�������
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        for (int i = 0; i < _graphDate[v].size(); i++) {
            if (_graphDate[v][i]->other(v) == w) {
                return true;
            }
        }

        return false;
    }

    // ��ʾͼ����Ϣ
    void show() {

        for (int i = 0; i < _vertexNum; i++) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < _graphDate[i].size(); j++)
                cout << "( to:" << _graphDate[i][j]->W() << ",wt:" << _graphDate[i][j]->weight() << ")\t";
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
        adjIterator(SparseGraph& graph, int v) :_graph(graph), _vertex(v),_index(0) {

        }

        ~adjIterator() {

        }

        // ����ͼG���붥��v�����ӵĵ�һ������
        Edge<Weight>* begin() {
            _index = 0;
            if (_graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][0];
            }

            // ��û�ж����v������, �򷵻�nullptr
            return nullptr;
        }

        // ����ͼG���붥��v�����ӵ���һ������
        Edge<Weight>* next() {
            _index++;

            if (_index < _graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][_index];
            }

            // ��û�ж����v������, �򷵻�nullptr
            return nullptr;
        }

        // �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
        bool end() {
            return _index >= _graph._graphDate[_vertex].size();
        }

    private:
        SparseGraph& _graph;  //���õ�ϡ��ͼ
        int _vertex;  //ͼ�Ķ���
        int _index;  //����
    };
};