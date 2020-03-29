#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename Item>
class MinHeap {
public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MinHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    // 构造函数, 通过一个给定数组创建一个最小堆
    // 该构造堆的过程, 时间复杂度为O(n)
    MinHeap(Item arr[], int n) {
        _data = new Item[n + 1];
        _capacity = n;

        for (int i = 0; i < n; i++) {
            _data[i + 1] = arr[i];
        }
        _count = n;

        for (int i = _count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MinHeap() {
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

    // 向最小堆中插入一个新的元素 item
    void insert(Item item) {
        assert(_count < _capacity);
        _count++;
        _data[_count] = item;

        shiftUp(_count);
    }

    /// 从最小堆中取出堆顶元素, 即堆中所存储的最小数据
    Item extractMin() {
        assert(!isEmpty());
        Item item= _data[1];
        _data[1] = _data[_count];
        _count--;
        shiftDown(1);

        return item;
    }

    // 获取最大堆中的堆顶元素
    Item getMin() {
        assert(!isEmpty());
        return data[1];
    }

private:
    void shiftUp(int key) {
        while (key > 1 && _data[key] < _data[key / 2]) {
            swap(_data[key], _data[key / 2]);
            key /= 2;
        }
    }

    void shiftDown(int key) {
        //注意不要越界
        while (2 * key <= _count) {
            int next = 2 * key;

            if (next + 1 <= _count&&_data[next + 1] < _data[next]) {
                next++;
            }

            if (_data[key] < _data[next]) {
                break;
            }

            swap(_data[key], _data[next]);
            key = next;
        }
    }

private:
    Item* _data;
    int _capacity;
    int _count;
};