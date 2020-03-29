#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

// ��ʹ��һ�����������, ֱ����ԭ�����Ͻ���ԭ�صĶ�����
template<typename T>
void heapSortInPlace(T arr[], int n) {
    // ע�⣬��ʱ���ǵĶ��Ǵ�0��ʼ������
    // ��(���һ��Ԫ�ص�����-1)/2��ʼ
    // ���һ��Ԫ�ص����� = n-1
    for (int i = (n - 2) / 2; i >= 0; i--) {
        _shiftDown(arr, n, i);
    }

    //������ֻ��һ��Ԫ�ص�ʱ��Ͳ��ý�����
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        _shiftDown(arr, i, 0);
    }
}

// ԭʼ��shiftDown����
template<typename T>
void _shiftDown(T arr[],int n,int key) {
    //���ӽڵ㲻Խ��
    while (2 * key + 1 < n) {
        int next = 2 * key + 1;
        if (next + 1 < n && arr[next] < arr[next + 1]) {
            next++;
        }

        if (arr[key] >= arr[next]) {
            break;
        }

        swap(arr[key], arr[next]);
        key = next;
    }
}

template<typename T>
void heapSortInPlace2(T arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        _shiftDown2(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        _shiftDown2(arr, i, 0);
    }
}

// �Ż���shiftDown����, ʹ�ø�ֵ�ķ�ʽȡ�����ϵ�swap,
template<typename T>
void _shiftDown2(T arr[], int n, int key) {
    T v = arr[key];

    while (2 * key + 1 < n) {
        int next = 2 * key + 1;
        if (next + 1 < n && arr[next] < arr[next + 1]) {
            next++;
        }

        if (v >= arr[next]) {
            break;
        }
        arr[key] = arr[next];
        key = next;
    }

    arr[key] = v;
}