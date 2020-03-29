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
    // ���캯��, ����һ���ն�, ������capacity��Ԫ��
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

    // ���캯��, ͨ��һ���������鴴��һ����С��
    // �ù���ѵĹ���, ʱ�临�Ӷ�ΪO(n)
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

    // ���ض��е�Ԫ�ظ���
    int size() {
        return _count;
    }

    // ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
    bool isEmpty() {
        return _count == 0;
    }

    // ����С�������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
    // �����i���û�����,�Ǵ�0������
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

    // ����С����ȡ���Ѷ�Ԫ��, ���������洢����С����
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

    // ��ȡ��С���еĶѶ�Ԫ��
    Item getMin() {
        assert(!isEmpty());
        return _data[_index[1]];
    }

    // ����С��������ȡ���Ѷ�Ԫ�ص�����
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

    // ��ȡ��С�������еĶѶ�Ԫ�ص�����
    int getMinIndex() {
        assert(!isEmpty());
        return _index[1] - 1;
    }

    // ��ȡ��С������������Ϊi��Ԫ��
    Item getItem(int i) {
        assert(contain(i));
        return _data[i + 1];
    }

    // ����С������������Ϊi��Ԫ���޸�ΪnewItem
    void change(int i, Item newItem) {
        assert(contain(i));

        i += 1;
        _data[i] = newItem;

        // �ҵ�indexes[j] = i, j��ʾdata[i]�ڶ��е�λ��
        // ֮��shiftUp(j), ��shiftDown(j)
        int j = _reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

    // ������i���ڵ�λ���Ƿ����Ԫ��
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
        //ע�ⲻҪԽ��
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
    Item* _data;   // ��С�������е�����
    int* _index;   // ��С�������е�����
    int* _reverse; // ��С�������еķ�������, reverse[i] = x ��ʾ����i��x��λ��
    int _capacity;
    int _count;
};