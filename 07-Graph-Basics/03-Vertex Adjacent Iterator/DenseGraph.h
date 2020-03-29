#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// ����ͼ - �ڽӾ���
class DenseGraph {
public:
    DenseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
        _graphDate = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    ~DenseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        if (hasEdge(v, w)) {
            return;
        }

        _graphDate[v][w] = true;
        if (!_directed) {
            _graphDate[w][v] = true;
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        return _graphDate[v][w];
    }

private:
    int _vertexNum;    // �ڵ���
    int _edgeNum;    // ����
    bool _directed;  // �Ƿ�Ϊ����ͼ
    vector<vector<bool>> _graphDate;  // ͼ�ľ�������

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
        int begin() {
            // ������-1��ʼ, ��Ϊÿ�α�������Ҫ����һ��next()
            _index = -1;
            return next();
        }

        // ����ͼG���붥��v�����ӵ���һ������
        int next() {
            // �ӵ�ǰindex��ʼ�������, ֱ���ҵ�һ��_graphDate[v][index]Ϊtrue
            for (_index += 1; _index < _graph.V(); _index++) {
                if (_graph._graphDate[_vertex][_index]) {
                    return _index;
                }
            }

            // ��û�ж����v������, �򷵻�-1
            return -1;
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