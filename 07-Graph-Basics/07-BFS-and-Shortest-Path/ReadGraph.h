#pragma once

#include <cassert>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// 读取图算法
template<typename Graph>
class ReadGraph {
public:
    // 从文件filename中读取图的信息, 存储进图graph中
    ReadGraph(Graph& graph, const string& filename) {
        ifstream file(filename);
        assert(file.is_open());

        string line;
        int V, E;

        // 第一行读取图中的节点个数和边的个数
        assert(getline(file, line));
        stringstream ss(line);
        ss >> V >> E;

        assert(V == graph.V());

        // 读取每一条边的信息
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            stringstream ss(line);

            int a, b;
            ss >> a >> b;

            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);

            graph.addEdge(a, b);
        }
    }
};