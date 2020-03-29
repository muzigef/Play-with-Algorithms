#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(nullptr));
    _quickSort(arr, 0, n - 1);
}

// ��arr[rangeL,rangeR]���ֽ��п�������
template<typename T>
void _quickSort(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }
    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition(arr, rangeL, rangeR);

    _quickSort(arr, rangeL, index - 1);
    _quickSort(arr, index + 1, rangeR);
}

// ��arr[rangeL,rangeR]���ֽ���_quickPartition����
// ����index, ʹ��arr[rangeL, index - 1] < arr[index] ; arr[index + 1, rangeR] > arr[index]
template<typename T>
int _quickPartition(T arr[], int rangeL, int rangeR) {
    // �����arr[rangeR, rangeL]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    //˼����Ϊʲô�÷�ʽ�ܹ���Ч�Ż�������������������أ�
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];
    int j = rangeL;

    for (int i = rangeL + 1; i <= rangeR; i++) {
        if (arr[i] < temp) {
            j++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[rangeL]);
    return j;
}

//�����ҳ���һ������arr[rangeL]���Ӹ�ֵ��ʼ���������������������������Ч��
//�Լ������Ż�
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(nullptr));
    _quickSort2(arr, 0, n - 1);
}

// ��arr[rangeL,rangeR]���ֽ��п�������
template<typename T>
void _quickSort2(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }

    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition2(arr, rangeL, rangeR);

    _quickSort2(arr, rangeL, index - 1);
    _quickSort2(arr, index + 1, rangeR);
}

template<typename T>
int _quickPartition2(T arr[], int rangeL, int rangeR) {
    // �����arr[rangeR, rangeL]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];
    int j = rangeL;

    //�����ҳ���һ������arr[rangeL]���Ӹ�ֵ��ʼ���������������������������Ч��
    for (int i = rangeL + 1; i <= rangeR; i++) {
        if (arr[i] >= temp) {
            j = i - 1;
            break;
        }
    }

    for (int i = j + 1; i <= rangeR; i++) {
        if (arr[i] < temp) {
            j++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[rangeL]);
    return j;
}

