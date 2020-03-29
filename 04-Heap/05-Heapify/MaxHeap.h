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
    // ���캯��, ����һ���ն�, ������capacity��Ԫ��
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    // ���캯��, ͨ��һ���������鴴��һ������
    // �ù���ѵĹ���, ʱ�临�Ӷ�ΪO(n)
    MaxHeap(Item arr[], int n) {
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

    // �������в���һ���µ�Ԫ�� item
    void insert(Item item) {
        assert(_count < _capacity);
        _count++;
        _data[_count] = item;

        shiftUp(_count);
    }

    /// ��������ȡ���Ѷ�Ԫ��, ���������洢���������
    Item extractMax() {
        assert(!isEmpty());
        Item item= _data[1];
        _data[1] = _data[_count];
        _count--;
        shiftDown(1);

        return item;
    }

    // ��ȡ�����еĶѶ�Ԫ��
    Item getMax() {
        assert(!isEmpty());
        return data[1];
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

        //ע�ⲻҪԽ��
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