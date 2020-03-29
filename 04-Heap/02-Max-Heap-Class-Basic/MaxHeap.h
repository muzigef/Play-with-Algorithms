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
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
    }

    ~MaxHeap() {
        delete[] _data;
    }

    // 返回堆中的元素个数
    int size() {
        return _count;
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty() {
        return _count == 0;
    }

private:
    Item* _data;
    int _count;
};