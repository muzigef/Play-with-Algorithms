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
    // ���캯��, ����һ���ն�, ������capacity��Ԫ��
    MinHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    // ���캯��, ͨ��һ���������鴴��һ����С��
    // �ù���ѵĹ���, ʱ�临�Ӷ�ΪO(n)
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

    // ���ض��е�Ԫ�ظ���
    int size() {
        return _count;
    }

    // ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
    bool isEmpty() {
        return _count == 0;
    }

    // ����С���в���һ���µ�Ԫ�� item
    void insert(Item item) {
        assert(_count < _capacity);
        _count++;
        _data[_count] = item;

        shiftUp(_count);
    }

    /// ����С����ȡ���Ѷ�Ԫ��, ���������洢����С����
    Item extractMin() {
        assert(!isEmpty());
        Item item= _data[1];
        _data[1] = _data[_count];
        _count--;
        shiftDown(1);

        return item;
    }

    // ��ȡ�����еĶѶ�Ԫ��
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
        //ע�ⲻҪԽ��
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