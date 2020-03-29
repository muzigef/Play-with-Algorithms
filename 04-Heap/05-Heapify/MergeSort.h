#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

template<typename T>
void mergeSort(T arr[], int n) {
    assert(n);
    _mergeSort(arr, 0, n - 1);
}

//�ݹ�ʹ�ù鲢����,����[rangeL,rangeR]��Χ�ڵ�Ԫ��,ע�����Ҷ��Ǳ�����
template<typename T>
void _mergeSort(T arr[], int rangeL, int rangeR) {
    // �Ż�2: ����С��ģ����, ʹ�ò�������
    if (rangeR - rangeL <= 16) {
        insertionSort(arr, rangeL, rangeR);
        return;
    }

    int center = (rangeR - rangeL) / 2 + rangeL;
    _mergeSort(arr, rangeL, center);
    _mergeSort(arr, center + 1, rangeR);

    // �Ż�1: ����arr[center] <= arr[center + 1]�����,������merge
    // ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
    if (arr[center] > arr[center + 1]) {
        _merge(arr, rangeL, center, rangeR);
    }
}

//�鲢[rangeL,center]��[center+1,rangeR]����
template<typename T>
void _merge(T arr[], int rangeL, int center, int rangeR) {
    //iָ����벿�ֵ���ʼ����λ��rangeL��
    int i = rangeL;
    //jָ���Ұ벿����ʼ����λ��center + 1
    int j = center + 1;

    //��ʼ��һ����СΪrangeR - rangeL + 1������,���ڴ��������Ԫ��
    //VS��֧�ֶ�̬��������, rangeL��rangeRֵ��δ֪��
    //������ʹ�� T a[rangeR - rangeL + 1]�ķ�ʽ����a�Ŀռ�,��Ҫʹ��new�ķ�ʽ
    T* a = new T[rangeR - rangeL + 1];

    for (int k = rangeL; k <= rangeR; k++) {
        if (i > center) {   // �����벿��Ԫ���Ѿ�ȫ���������
            a[k - rangeL] = arr[j];
            j++;
        }
        else if (j > rangeR) {   // ����Ұ벿��Ԫ���Ѿ�ȫ���������
            a[k - rangeL] = arr[i];
            i++;
        }
        else if(arr[i] < arr[j]) {   // ��벿����ָԪ�� < �Ұ벿����ָԪ��
            a[k - rangeL] = arr[i];
            i++;
        }
        else {   // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
            a[k - rangeL] = arr[j];
            j++;
        }
    }

    //��������Ԫ�ظ�ֵ��arr
    for (int k = rangeL; k <= rangeR; k++) {
        arr[k] = a[k - rangeL];
    }

    delete[] a;  //ɾ��new������a
}