#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

template<typename Item>
class MaxHeap {
public:
    // ���캯��, ����һ���ն�, ������capacity��Ԫ��
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
    }

    ~MaxHeap() {
        delete[] _data;
    }

    // ���ض��е�Ԫ�ظ���
    int size() {
        return _count;
    }

    // ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
    bool isEmpty() {
        return _count == 0;
    }

private:
    Item* _data;
    int _count;
};