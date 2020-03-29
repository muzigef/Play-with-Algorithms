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
    // ���캯��, ����һ���ն�, ������capacity��Ԫ��
    IndexMaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _index = new int[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    // ���캯��, ͨ��һ���������鴴��һ������
    // �ù���ѵĹ���, ʱ�临�Ӷ�ΪO(n)
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

    // ���ض��е�Ԫ�ظ���
    int size() {
        return _count;
    }

    // ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
    bool isEmpty() {
        return _count == 0;
    }

    // ������������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
    // �����i���û�����,�Ǵ�0������
    void insert(int i, Item item) {
        assert(_count < _capacity);
        assert(i >= 0 && i + 1 <= _capacity);

        i++;
        _count++;

        _data[i] = item;
        _index[_count] = i;

        shiftUp(_count);
    }

    // ��������ȡ���Ѷ�Ԫ��, ���������洢���������
    Item extractMax() {
        assert(!isEmpty());
        Item item= _data[_index[1]];
        _index[1] = _index[_count];
        _count--;
        shiftDown(1);

        return item;
    }

    // ��ȡ�����еĶѶ�Ԫ��
    Item getMax() {
        assert(!isEmpty());
        return _data[_index[1]];
    }

    // �������������ȡ���Ѷ�Ԫ�ص�����
    int extractMaxIndex() {
        assert(!isEmpty());

        int index = _index[1] - 1;
        swap(_index[1], _index[_count]);
        _count--;
        shiftDown(1);

        return index;
    }

    // ��ȡ����������еĶѶ�Ԫ�ص�����
    int getMaxIndex() {
        assert(!isEmpty());
        return _index[1] - 1;
    }

    // ��ȡ���������������Ϊi��Ԫ��
    Item getItem(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return _data[i + 1];
    }

    // �����������������Ϊi��Ԫ���޸�ΪnewItem
    void change(int i, Item newItem) {

        i += 1;
        _data[i] = newItem;

        // �ҵ�indexes[j] = i, j��ʾdata[i]�ڶ��е�λ��
        // ֮��shiftUp(j), ��shiftDown(j)
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
        //ע�ⲻҪԽ��
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
    Item* _data;  // ����������е�����
    int* _index;  // ����������е�����
    int _capacity;
    int _count;
};