#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

//��·����ֻ���д����ظ����ݵ�����Ч�ʱȽϸߣ�
//��ͨ���ݻ��߻������������Ч�ʻ�����˫·���źͻ�������
template<typename T>
void quickSort3Ways(T arr[],int n) {
    _quickSort3Ways(arr, 0, n - 1);
}

// ��arr[rangeL,rangeR]���ֽ��п�������
template<typename T>
void _quickSort3Ways(T arr[], int rangeL, int rangeR) {
    if (rangeL >= rangeR) {
        return;
    }
    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    // �����arr[rangeR, rangeL]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    swap(arr[rangeL], arr[rand() % (rangeR - rangeL + 1) + rangeL]);

    T temp = arr[rangeL];

    int lt = rangeL;     // arr[rangeL+1,lt] < temp
    int gt = rangeR + 1; // arr[gt...rangeR] > temp
    int i = rangeL + 1;    // arr[lt+1...i) == temp
    while (i < gt) {
        if (arr[i] < temp) {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        }
        else if (arr[i] > temp) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        }
        else { // arr[i] == temp
            i++;
        }
    }

    //����֮��arr[lt] = temp 
    swap(arr[rangeL], arr[lt]); 

    _quickSort3Ways(arr, rangeL, lt - 1);
    _quickSort3Ways(arr, gt, rangeR);
}
