#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

template<typename Graph>
class ShortestPath {
public:
    // 构造函数, 寻找无权图graph从s点到其他点的最短路径
    ShortestPath(Graph& graph, int s) :_graph(graph) {
        // 算法初始化
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

        // 无向图最短路径算法, 从s开始广度优先遍历整张图
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

    // 查询从s点到w点是否有路径
    bool hasPath(int w) {
        return _visited[w];
    }

    // 查询从s点到w点的路径, 存放在vec中
    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < _graph.V());

        // 通过_from数组逆向查找到从s到w的路径, 存放到栈中
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = _from[p];

        }

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        vec.clear();  //清空vec
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
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

    // 查看从s点到w点的最短路径长度
    int length(int w) {
        assert(w >= 0 && w < _graph.V());
        return _order[w];
    }

private:
    Graph& _graph;    // 图的引用
    bool* _visited;   // 记录dfs的过程中节点是否被访问
    int* _from;       // 记录路径, _from[i]表示查找的路径上i的上一个节
    int* _order;      // 记录路径中节点的次序。_order[i]表示i节点在路径中的次序。
    int _s;           // 起始点
};