#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {
public:
    // ���캯��, �����Ȩͼ����ͨ����
    Component(Graph& graph) :_graph(graph) {

        // �㷨��ʼ��
        _visited = new bool[graph.V()];
        _id = new int[graph.V()];
        _ccount = 0;

        for (int i = 0; i < graph.V(); i++) {
            _visited[i] = false;
            _id[i] = -1;
        }

        // ��ͼ����ͨ����
        for (int i = 0; i < graph.V(); i++) {
            if (!_visited[i]) {
                dfs(i);
                _ccount++;
            }
        }
    }

    ~Component() {
        delete[] _visited;
        delete[] _id;
    }

    // ����ͼ����ͨ��������
    int count() {
        return _ccount;
    }

    // ��ѯ��v�͵�w�Ƿ���ͨ
    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return _id[v] == _id[w];
    }

private:
    // ͼ��������ȱ���
    void dfs(int v) {
        _visited[v] = true;
        _id[v] = _ccount;

        typename Graph::adjIterator adj(_graph, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!_visited[i]) {
                dfs(i);
            }
        }
    }

private:
    Graph& _graph;    // ͼ������
    bool* _visited;   // ��¼dfs�Ĺ����нڵ��Ƿ񱻷���
    int _ccount;      // ��¼��ͨ��������
    int* _id;         // ÿ���ڵ�����Ӧ����ͨ�������,���鼯
};