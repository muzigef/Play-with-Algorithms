#pragma once

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

template<typename Graph>
class Path {
public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    Path(Graph& graph, int s) :_graph(graph) {
        // 算法初始化
        assert(s >= 0 && s < _graph.V());

        _visited = new bool[graph.V()];
        _from = new int[graph.V()];
        _s = s;

        for (int i = 0; i < graph.V(); i++) {
            _visited[i] = false;
            _from[i] = -1;
        }

        // 寻路算法
        dfs(s);
    }

    ~Path() {
        delete[] _visited;
        delete[] _from;
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

private:
    // 图的深度优先遍历
    void dfs(int v) {
        _visited[v] = true;

        typename Graph::adjIterator adj(_graph, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!_visited[i]) {
                _from[i] = v;
                dfs(i);
            }
        }
    }

private:
    Graph& _graph;    // 图的引用
    bool* _visited;   // 记录dfs的过程中节点是否被访问
    int* _from;       // 记录路径, _from[i]表示查找的路径上i的上一个节
    int _s;           // 起始点
};