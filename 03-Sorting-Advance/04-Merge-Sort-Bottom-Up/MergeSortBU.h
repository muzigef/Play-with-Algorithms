#pragma once

#include <cassert>
#include <algorithm>
#include "InsertionSort.h"

// ʹ���Ե����ϵĹ鲢�����㷨
// Merge Sort BU Ҳ��һ��O(nlogn)���Ӷȵ��㷨����Ȼֻʹ������forѭ��
// ���ԣ�Merge Sort BUҲ������1��֮�����ɴ���100��������������
// ע�⣺��Ҫ���׸���ѭ���������ж��㷨�ĸ��Ӷȣ�Merge Sort BU����һ������
// �����ⲿ�����壬�Ƽ����ҵġ���ת�㷨���ԡ��γ̣��ڶ��£��������еĸ��Ӷȷ���������

//Merge Sort Bottom Up ���Ż��汾
template <typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz < n; sz += sz)  //szΪ�����鲢�������
        //i < n - sz��������i + sz - 1��Խ��
        for (int i = 0; i < n - sz; i += sz + sz)  //��ǰ�鲢��ĸ����鲢��Ԫ
            // �� arr[i...i+sz-1] �� arr[i+sz...i+2*sz-1] ���й鲢
            //min����i + sz + sz - 1,��Խ��
            _mergeBU(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

//Merge Sort Bottom Up �Ż��汾
template <typename T>
void mergeSortBUAdvance(T arr[], int n) {

    // ����С����, ʹ�ò��������Ż�
    for (int i = 0; i < n; i += 16)
        insertionSort(arr, i, min(i + 15, n - 1));

    for (int sz = 16; sz < n; sz += sz)  //szΪ�����鲢�������
        for (int i = 0; i < n - sz; i += sz + sz)  //��ǰ�鲢��ĸ����鲢��Ԫ
            // ����arr[mid] <= arr[mid+1]�����,������merge
            if (arr[i + sz - 1] > arr[i + sz])
                _mergeBU(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

//�鲢[rangeL,center]��[center+1,rangeR]����
template<typename T>
void _mergeBU(T arr[], int rangeL, int center, int rangeR) {
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
        else if (arr[i] < arr[j]) {   // ��벿����ָԪ�� < �Ұ벿����ָԪ��
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