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
    };

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

private:
    void shiftUp(int key) {
        int index = key;
        while (index > 1 && _data[index] > _data[index / 2]) {
            swap(_data[index], _data[index / 2]);
            index = index / 2;
        }
    }

public:
    // ����״��ӡ�����ѽṹ
    void testPrint() {
        // ���ǵ�testPrintֻ�ܴ�ӡ100��Ԫ�����ڵĶѵ���״��Ϣ
        if (size() >= 100) {
            cout << "This print function can only work for less than 100 int";
            return;
        }

        // ���ǵ�testPrintֻ�ܴ���������Ϣ
        if (typeid(Item) != typeid(int)) {
            cout << "This print function can only work for int item";
            return;
        }

        cout << "The max heap size is: " << size() << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // ���ǵ�testPrintҪ����е�����������[0, 100)�ķ�Χ��
            assert(_data[i] >= 0 && _data[i] < 100);
            cout << _data[i] << " ";
        }
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(_count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(_data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }
private:
    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {
        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {
        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

private:
    Item* _data;
    int _capacity;
    int _count;
};