#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

//˫·����
//��Դ��ڴ����ظ����������Ż�
//����������Ի��������������������Ż�

//˫·���������������ܱȽϺã����������͵���������Ч�ʾ����ڻ�������
//�����ڴ����ظ�����ʱ������Ч�ʲ�����·����

template<typename T>
void quickSort2Ways(T arr[], int n) {
    srand(time(nullptr));
    _quickSort2Ways(arr, 0, n - 1);
}

// ��arr[rangeL,rangeR]���ֽ��п�������
template<typename T>
void _quickSort2Ways(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }

    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int index = _quickPartition2Ways(arr, rangeL, rangeR);

    _quickSort2Ways(arr, rangeL, index - 1);
    _quickSort2Ways(arr, index + 1, rangeR);
}

// ˫·���������partition
// ����p, ʹ��arr[rangeL��index] <= arr[index] ; arr[index+1��rangeR] >= arr[index]
// ˫·���Ŵ����Ԫ�����õ���arr[index]��ʱ��Ҫע�⣬��������ע�ͣ���
template<typename T>
int _quickPartition2Ways(T arr[], int rangeL, int rangeR) {
    // �����arr[rangeR, rangeL]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];

    // arr[rangeL+1��i) <= temp; arr(j��rangeR] >= temp
    int i = rangeL + 1, j = rangeR;
    while (true) {
        // ע������ı߽�, arr[i] < temp, ������arr[i] <= temp
        // ˼��һ��Ϊʲô?
        while (i <= rangeR && arr[i] < temp)
            i++;

        // ע������ı߽�, arr[j] > temp, ������arr[j] >= temp
        // ˼��һ��Ϊʲô?
        while (j >= rangeL + 1 && arr[j] > temp)
            j--;

        // ��������������߽���趨, �е�ͬѧ�ڿγ̵��ʴ����кܺõĻش�:)
        // ��ҿ��Բο�: http://coding.imooc.com/learn/questiondetail/4920.html

        if (i > j)
            break;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }


    swap(arr[j], arr[rangeL]);
    return j;
}