#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename Item>
class MaxHeap {
public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    };

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

    // 向最大堆中插入一个新的元素 item
    void insert(Item item) {
        assert(_count < _capacity);
        _count++;
        _data[_count] = item;

        shiftUp(_count);
    }

    /// 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    Item extractMax() {
        assert(!isEmpty());
        Item item= _data[1];
        _data[1] = _data[_count];
        _count--;
        shiftDown(1);

        return item;
    }

private:
    void shiftUp(int key) {
        int index = key;
        while (index > 1 && _data[index] > _data[index / 2]) {
            swap(_data[index], _data[index / 2]);
            index /= 2;
        }
    }

    void shiftDown(int key) {
        int index = key;

        //注意不要越界
        while (2 * index <= _count) {
            int next = 2 * index;

            if (next + 1 <= _count&&_data[next + 1] > _data[next]) {
                next++;
            }

            if (_data[index] > _data[next]) {
                break;
            }

            swap(_data[index], _data[next]);
            index = next;
        }
    }

private:
    Item* _data;
    int _capacity;
    int _count;
};