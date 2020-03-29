#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include "IndexMinHeap.h"
#include "Edge.h"

using namespace std;

// Dijkstra算法求最短路径
template<typename Graph, typename Weight>
class Dijkstra {
public:
    // 构造函数, 使用Dijkstra算法求最短路径
    Dijkstra(Graph& graph, int source) :_graph(graph) {
        // 算法初始化
        assert(source >= 0 && source < _graph.V());
        _source = source;
        _marked = new bool[_graph.V()];
        _distTo = new int[_graph.V()];

        for (int i = 0; i < graph.V(); i++) {
            _marked[i] = false;
            _distTo[i] = Weight();
            _from.push_back(nullptr);
        }

        // 使用索引堆记录当前找到的到达每个顶点的最短距离
        IndexMinHeap<Weight> priorityQueue(_graph.V());

        // 对于其实点_source进行初始化
        _distTo[_source] = Weight();
        _marked[_source] = true;
        // 这里我们from[s]的内容是new出来的, 注意要在析构函数里delete掉
        _from[_source] = new Edge<Weight>(_source, _source, Weight());
        priorityQueue.insert(_source, _distTo[_source]);

        while (!priorityQueue.isEmpty()) {
            int v = priorityQueue.extractMinIndex();
            _marked[v] = true;

            // 对v的所有相邻节点进行更新
            typename Graph::adjIterator adj(_graph, v);
            for (Edge<Weight>* edge = adj.begin(); !adj.end(); edge = adj.next()) {
                int w = edge->other(v);
                // 如果从v点到w点的最短路径已经找到，则忽略
                if (_marked[w]) {
                    continue;
                }

                // 如果从v点到w点的最短路径还没有找到
                // 如果w点以前没有访问过
                if (!_from[w]) {
                    _distTo[w] = _distTo[v] + edge->weight();
                    _from[w] = edge;
                    priorityQueue.insert(w, _distTo[w]);
                }
                // 或者访问过, 但是通过当前的v点到w点距离更短, 则进行更新
                else if (_distTo[v] + edge->weight() < _distTo[w]) {
                    _distTo[w] = _distTo[v] + edge->weight();
                    _from[w] = edge;
                    priorityQueue.change(w, _distTo[w]);
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] _marked;
        delete[] _distTo;
        delete _from[_source];
    }

    // 返回从s点到w点的最短路径长度
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        assert(hasPathTo(w));
        return _distTo[w];
    }

    // 判断从s点到w点是否联通
    bool hasPathTo(int w) {
        assert(w >= 0 && w < _graph.V());
        return _marked[w];
    }

    // 寻找从_source到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath(int w, vector<Edge<Weight>> &vec) {

        assert(w >= 0 && w < _graph.V());
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
    Graph& _graph;   // 图的引用
    int _source;  // 起始点
    vector<Edge<Weight>*> _from;  // _from[i]记录最短路径中, 到达i点的边是哪一条
    Weight* _distTo;  // _distTo[i]存储从起始点s到i的最短路径长度
    bool* _marked;  // 标记数组, 在算法运行过程中标记节点i是否被访问
};