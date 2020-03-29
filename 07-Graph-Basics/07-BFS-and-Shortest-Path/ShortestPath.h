#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

template<typename Graph>
class ShortestPath {
public:
    // ���캯��, Ѱ����Ȩͼgraph��s�㵽����������·��
    ShortestPath(Graph& graph, int s) :_graph(graph) {
        // �㷨��ʼ��
        assert(s >= 0 && s < _graph.V());

        _visited = new bool[graph.V()];
        _from = new int[graph.V()];
        _order = new int[graph.V()];
        _s = s;

        for (int i = 0; i < graph.V(); i++) {
            _visited[i] = false;
            _from[i] = -1;
            _order[i] = -1;
        }

        // ����ͼ���·���㷨, ��s��ʼ������ȱ�������ͼ
        queue<int> q;
        q.push(s);
        _visited[s] = true;
        _order[s] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(graph, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!_visited[i]) {
                    q.push(i);
                    _visited[i] = true;
                    _from[i] = v;
                    _order[i] = _order[v] + 1;
                }
            }
        }
    }

    ~ShortestPath() {
        delete[] _visited;
        delete[] _from;
        delete[] _order;
    }

    // ��ѯ��s�㵽w���Ƿ���·��
    bool hasPath(int w) {
        return _visited[w];
    }

    // ��ѯ��s�㵽w���·��, �����vec��
    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < _graph.V());

        // ͨ��_from����������ҵ���s��w��·��, ��ŵ�ջ��
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = _from[p];

        }

        // ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
        vec.clear();  //���vec
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    // ��ӡ����s�㵽w���·��
    void showPath(int w) {
        assert(w >= 0 && w < _graph.V());
        assert(hasPath(w));

        vector<int> vec;
        path(w, vec);

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }

    // �鿴��s�㵽w������·������
    int length(int w) {
        assert(w >= 0 && w < _graph.V());
        return _order[w];
    }

private:
    Graph& _graph;    // ͼ������
    bool* _visited;   // ��¼dfs�Ĺ����нڵ��Ƿ񱻷���
    int* _from;       // ��¼·��, _from[i]��ʾ���ҵ�·����i����һ����
    int* _order;      // ��¼·���нڵ�Ĵ���_order[i]��ʾi�ڵ���·���еĴ���
    int _s;           // ��ʼ��
};