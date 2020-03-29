#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename Item>
class IndexMinHeap {
public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    IndexMinHeap(int capacity) {
        _data = new Item[capacity + 1];
        _index = new int[capacity + 1];
        _reverse = new int[capacity + 1];
        for (int i = 0; i < capacity; i++) {
            _reverse[i] = 0;
        }

        _count = 0;
        _capacity = capacity;
    }

    // 构造函数, 通过一个给定数组创建一个最小堆
    // 该构造堆的过程, 时间复杂度为O(n)
    IndexMinHeap(Item arr[], int n) {
        _data = new Item[n + 1];
        _index = new int[n + 1];
        _reverse = new int[n + 1];
        for (int i = 0; i < n; i++) {
            _reverse[i] = 0;
        }

        _capacity = n;

        for (int i = 0; i < n; i++) {
            _data[i + 1] = arr[i];
            _index[i + 1] = i + 1;
            _reverse[i + 1] = i + 1;
        }
        _count = n;

        for (int i = _count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~IndexMinHeap() {
        delete[] _data;
        delete[] _index;
        delete[] _reverse;
    }

    // 返回堆中的元素个数
    int size() {
        return _count;
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty() {
        return _count == 0;
    }

    // 向最小索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item) {
        assert(_count + 1 <= _capacity);
        assert(i + 1 >= 1 && i + 1 <= _capacity);

        i++;
        _count++;

        _data[i] = item;
        _index[_count] = i;
        _reverse[i] = _count;;

        shiftUp(_count);
    }

    // 从最小堆中取出堆顶元素, 即堆中所存储的最小数据
    Item extractMin() {
        assert(!isEmpty());
        Item item= _data[_index[1]];
        _index[1] = _index[_count];
        _reverse[_index[1]] = 1;
        _reverse[_index[_count]] = 0;
        _count--;
        shiftDown(1);

        return item;
    }

    // 获取最小堆中的堆顶元素
    Item getMin() {
        assert(!isEmpty());
        return _data[_index[1]];
    }

    // 从最小索引堆中取出堆顶元素的索引
    int extractMinIndex() {
        assert(!isEmpty());

        int index = _index[1] - 1;
        swap(_index[1], _index[_count]);
        _reverse[_index[1]] = 1;
        _reverse[_index[_count]] = 0;
        _count--;
        shiftDown(1);

        return index;
    }

    // 获取最小索引堆中的堆顶元素的索引
    int getMinIndex() {
        assert(!isEmpty());
        return _index[1] - 1;
    }

    // 获取最小索引堆中索引为i的元素
    Item getItem(int i) {
        assert(contain(i));
        return _data[i + 1];
    }

    // 将最小索引堆中索引为i的元素修改为newItem
    void change(int i, Item newItem) {
        assert(contain(i));

        i += 1;
        _data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        int j = _reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

    // 看索引i所在的位置是否存在元素
    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= _capacity);
        return _reverse[i + 1] != 0;
    }

private:
    void shiftUp(int key) {
        while (key > 1 && _data[_index[key]] < _data[_index[key / 2]]) {
            swap(_index[key], _index[key / 2]);
            _reverse[_index[key]] = key;
            _reverse[_index[key / 2]] = key / 2;
            key /= 2;
        }
    }

    void shiftDown(int key) {
        //注意不要越界
        while (2 * key <= _count) {
            int next = 2 * key;

            if (next + 1 <= _count&&_data[_index[next + 1]] < _data[_index[next]]) {
                next++;
            }

            if (_data[_index[key]] < _data[_index[next]]) {
                break;
            }

            swap(_index[key], _index[next]);
            _reverse[_index[key]] = key;
            _reverse[_index[next]] = next;
            key = next;
        }
    }

private:
    Item* _data;   // 最小索引堆中的数据
    int* _index;   // 最小索引堆中的索引
    int* _reverse; // 最小索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置
    int _capacity;
    int _count;
};