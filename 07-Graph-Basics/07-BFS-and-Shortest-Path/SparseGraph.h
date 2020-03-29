#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// ϡ��ͼ - �ڽӱ�
class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        assert(n);

        _vertexNum = n;
        _edgeNum = 0;   // ��ʼ��û���κα�
        _directed = directed;
        // _graphDate��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
        _graphDate = vector<vector<int>>(n, vector<int>());
    }

    ~SparseGraph() {

    }

    int V() { return _vertexNum; } // ���ؽڵ����
    int E() { return _edgeNum; } // ���رߵĸ���

    // ��ͼ�����һ����
    void addEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        //����hasEdge()ʱ�临�Ӷȹ��ߣ�һ���������ϡ��ͼ�����ж��Ƿ���ڱ�(v,w),
        //���Ը�ϡ��ͼ�п��ܴ���ƽ�бߣ�һ���������ͼ֮����������ƽ�б�
        //v != w��Ϊ�˷�ֹ�Ի���
        _graphDate[v].push_back(w);
        if (v != w && !_directed) {
            _graphDate[w].push_back(v);
        }

        _edgeNum++;
    }

    // ��֤ͼ���Ƿ��д�v��w�ı�
    // ����������£��ú�����ʱ�临�Ӷ�ΪO(V),V:�������
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < _vertexNum);
        assert(w >= 0 && w < _vertexNum);

        for (int i = 0; i < _graphDate[v].size(); i++) {
            if (_graphDate[v][i] == w) {
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
                cout << _graphDate[i][j] << "\t";
            cout << endl;
        }
    }

private:
    int _vertexNum;    // �ڵ���
    int _edgeNum;    // ����
    bool _directed;  // �Ƿ�Ϊ����ͼ
    vector<vector<int>> _graphDate;  // ͼ�ľ�������

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
        int begin() {
            _index = 0;
            if (_graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][0];
            }

            // ��û�ж����v������, �򷵻�-1
            return -1;
        }

        // ����ͼG���붥��v�����ӵ���һ������
        int next() {
            _index++;

            if (_index < _graph._graphDate[_vertex].size()) {
                return _graph._graphDate[_vertex][_index];
            }

            // ��û�ж����v������, �򷵻�-1
            return -1;
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