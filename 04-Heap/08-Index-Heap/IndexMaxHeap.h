#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename Item>
class IndexMaxHeap {
public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    IndexMaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _index = new int[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    // 构造函数, 通过一个给定数组创建一个最大堆
    // 该构造堆的过程, 时间复杂度为O(n)
    IndexMaxHeap(Item arr[], int n) {
        _data = new Item[n + 1];
        _index = new int[n + 1];
        _capacity = n;

        for (int i = 0; i < n; i++) {
            _data[i + 1] = arr[i];
            _index[i + 1] = i + 1;;
        }
        _count = n;

        for (int i = _count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~IndexMaxHeap() {
        delete[] _data;
        delete[] _index;
    }

    // 返回堆中的元素个数
    int size() {
        return _count;
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty() {
        return _count == 0;
    }

    // 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item) {
        assert(_count < _capacity);
        assert(i >= 0 && i + 1 <= _capacity);

        i++;
        _count++;

        _data[i] = item;
        _index[_count] = i;

        shiftUp(_count);
    }

    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    Item extractMax() {
        assert(!isEmpty());
        Item item= _data[_index[1]];
        _index[1] = _index[_count];
        _count--;
        shiftDown(1);

        return item;
    }

    // 获取最大堆中的堆顶元素
    Item getMax() {
        assert(!isEmpty());
        return _data[_index[1]];
    }

    // 从最大索引堆中取出堆顶元素的索引
    int extractMaxIndex() {
        assert(!isEmpty());

        int index = _index[1] - 1;
        swap(_index[1], _index[_count]);
        _count--;
        shiftDown(1);

        return index;
    }

    // 获取最大索引堆中的堆顶元素的索引
    int getMaxIndex() {
        assert(!isEmpty());
        return _index[1] - 1;
    }

    // 获取最大索引堆中索引为i的元素
    Item getItem(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return _data[i + 1];
    }

    // 将最大索引堆中索引为i的元素修改为newItem
    void change(int i, Item newItem) {

        i += 1;
        _data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        for (int j = 1; j <= _count; j++)
            if (_index[j] == i) {
                shiftUp(j);
                shiftDown(j);
            }
    }

private:
    void shiftUp(int key) {
        while (key > 1 && _data[_index[key]] > _data[_index[key / 2]]) {
            swap(_index[key], _index[key / 2]);
            key /= 2;
        }
    }

    void shiftDown(int key) {
        //注意不要越界
        while (2 * key <= _count) {
            int next = 2 * key;

            if (next + 1 <= _count&&_data[_index[next + 1]] > _data[_index[next]]) {
                next++;
            }

            if (_data[_index[key]] > _data[_index[next]]) {
                break;
            }

            swap(_index[key], _index[next]);
            key = next;
        }
    }

private:
    Item* _data;  // 最大索引堆中的数据
    int* _index;  // 最大索引堆中的索引
    int _capacity;
    int _count;
};