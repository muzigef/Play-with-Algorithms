#pragma once

#include <cassert>
#include <algorithm>

//����������ڻ����������������Ч�ʼ���
template<typename T>
void insertionSort(T arr[], int n) {
    assert(n);
    for (int i = 1; i < n; i++) { //i��1��ʼѭ������Ϊ0��Ĭ�������
        //��֤i�ں��ʵ�λ�ã����Ʋ�λ�˿���
        T e = arr[i];
        int j; // j����Ԫ��eӦ�ò����λ��
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

// ��arr[rangeL,rangeR]��Χ��������в�������
template<typename T>
void insertionSort(T arr[], int rangeL, int rangeR) {
    assert(rangeL <= rangeR);
    for (int i = rangeL + 1; i <= rangeR; i++) { //i��1��ʼѭ������Ϊ0��Ĭ�������
        //��֤i�ں��ʵ�λ�ã����Ʋ�λ�˿���
        T e = arr[i];
        int j; // j����Ԫ��eӦ�ò����λ��
        for (j = i; j > rangeL && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}