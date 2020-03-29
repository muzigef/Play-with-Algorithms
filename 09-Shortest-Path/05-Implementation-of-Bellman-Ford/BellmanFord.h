#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// Dijkstra算法求最短路径
template<typename Graph, typename Weight>
class BellmanFord {
public:
    // 构造函数, 使用Dijkstra算法求最短路径
    BellmanFord(Graph& graph, int source) :_graph(graph) {
        // 算法初始化
        assert(source >= 0 && source < _graph.V());
        _source = source;
        _distTo = new int[_graph.V()];

        for (int i = 0; i < graph.V(); i++) {
            _distTo[i] = Weight();
            _from.push_back(nullptr);
        }


        // 对于其实点_source进行初始化
        // 设置distTo[s] = 0, 并且让from[s]不为nullptr, 表示初始s节点可达且距离为0
        _distTo[_source] = Weight();
        // 这里我们from[s]的内容是new出来的, 注意要在析构函数里delete掉
        _from[_source] = new Edge<Weight>(_source, _source, Weight());

        // Bellman-Ford的过程
        // 进行V-1次循环, 每一次循环求出从起点到其余所有点, 最多使用pass步可到达的最短距离
        for (int pass = 1; pass < _graph.V(); pass++) {
            // 每次循环中对所有的边进行一遍松弛操作
            // 遍历所有边的方式是先遍历所有的顶点, 然后遍历和所有顶点相邻的所有边
            for (int v = 0; v < _graph.V(); v++) {
                // 使用我们实现的邻边迭代器遍历和所有顶点相邻的所有边
                typename Graph::adjIterator adj(_graph, v);
                for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                    int w = edge->other(v);
                    // 对于每一个边首先判断e->v()可达
                    // 之后看如果e->w()以前没有到达过， 显然我们可以更新distTo[e->w()]
                    // 或者e->w()以前虽然到达过, 但是通过这个e我们可以获得一个更短的距离, 即可以进行一次松弛操作, 我们也可以更新distTo[e->w()]
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

    // 返回图中是否有负权环
    bool negativeCycle() {
        return _hasNegativeCycle;
    }

    // 返回从s点到w点的最短路径长度
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        assert(!_hasNegativeCycle);
        assert(hasPathTo(w));
        return _distTo[w];
    }

    // 判断从s点到w点是否联通
    bool hasPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        return _from[w] != nullptr;
    }

    // 寻找从_source到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath(int w, vector<Edge<Weight>> &vec) {
        assert(w >= 0 && w < _graph.V());
        assert(!_hasNegativeCycle);
        assert(hasPathTo(w));

        // 通过from数组逆向查找到从_source到w的路径, 存放到栈中
        stack<Edge<Weight>*> s;
        Edge<Weight> *edge = _from[w];
        while (edge->V() != _source) {
            s.push(edge);
            edge = _from[edge->V()];
        }
        s.push(edge);

        // 从栈中依次取出元素, 获得顺序的从_source到w的路径
        while (!s.empty()) {
            edge = s.top();
            vec.push_back(*edge);
            s.pop();
        }
    }

    // 打印出从_source点到w点的路径
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
    // 判断图中是否有负权环
    bool detectNegativeCycle() {

        //对V个顶点做V-1次松弛操作
        for (int pass = 1; pass < _graph.V(); pass++) {
            //遍历V个顶点
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
    Graph& _graph;   // 图的引用
    int _source;  // 起始点
    vector<Edge<Weight>*> _from;  // _from[i]记录最短路径中, 到达i点的边是哪一条
    Weight* _distTo;  // _distTo[i]存储从起始点s到i的最短路径长度
    bool _hasNegativeCycle;      // 标记图中是否有负权环
};