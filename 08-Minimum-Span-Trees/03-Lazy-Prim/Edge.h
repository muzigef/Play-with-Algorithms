#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// �ߣ�Ϊ�˱�֤����ͼ��ϡ��ͼ�й�ͬ�Ľӿڣ������˸���
template<typename Weight>
class Edge {
public:
    // ���캯��
    Edge(int v,int w,Weight weight) {
        _v = v;
        _w = w;
        _weight = weight;
    }

    // �յĹ��캯��, ���еĳ�Ա������ȡĬ��ֵ
    Edge() {

    }

    ~Edge() {

    }

    // ���ص�һ������
    int V() {
        return _v;
    }

    // ���صڶ�������
    int W() {
        return _w;
    }

    // ����Ȩֵ
    Weight weight() {
        return _weight;
    }

    int other(int x) {
        assert(x == _v || x == _w);
        return x == _v ? _w : _v;
    }

    // ����ߵ���Ϣ
    friend ostream& operator<<(ostream& os, const Edge& edge) {
        return os << edge._v<< "-" << edge._w << ": " << edge._weight;
    }

    // �ߵĴ�С�Ƚ�, �ǶԱߵ�Ȩֵ�Ĵ�С�Ƚ�
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
    int _v;  //�ߵĵ�һ��
    int _w;  //�ߵĵڶ���
    Weight _weight;  //�ߵ�Ȩֵ��Ϊ����չ��ʹ��ģ����
};