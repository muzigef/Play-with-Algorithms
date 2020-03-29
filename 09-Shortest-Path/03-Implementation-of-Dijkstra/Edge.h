#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 边，为了保证稠密图和稀疏图有共同的接口，定义了该类
template<typename Weight>
class Edge {
public:
    // 构造函数
    Edge(int v,int w,Weight weight) {
        _v = v;
        _w = w;
        _weight = weight;
    }

    // 空的构造函数, 所有的成员变量都取默认值
    Edge() {

    }

    ~Edge() {

    }

    // 返回第一个顶点
    int V() {
        return _v;
    }

    // 返回第二个顶点
    int W() {
        return _w;
    }

    // 返回权值
    Weight weight() {
        return _weight;
    }

    int other(int x) {
        assert(x == _v || x == _w);
        return x == _v ? _w : _v;
    }

    // 输出边的信息
    friend ostream& operator<<(ostream& os, const Edge& edge) {
        return os << edge._v<< "-" << edge._w << ": " << edge._weight;
    }

    // 边的大小比较, 是对边的权值的大小比较
    bool operator<(const Edge& edge) {
        return _weight < edge._weight;
    }
    bool operator<=(const Edge& edge) {
        return _weight <= edge._weight;
    }
    bool operator>(const Edge& edge) {
        return _weight > edge._weight;
    }
    bool operator>=(const Edge& edge) {
        return _weight >= edge._weight;
    }
    bool operator==(const Edge& edge) {
        return _weight == edge._weight;
    }

private:
    int _v;  //边的第一个
    int _w;  //边的第二个
    Weight _weight;  //边的权值，为了扩展性使用模板类
};