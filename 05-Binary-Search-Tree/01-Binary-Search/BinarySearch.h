#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

//���ֲ����㷨����ı�������������
template<typename T>
int binarySearch(T arr[], int n, T target) {
    //��[rangeL, rangeR]��Χ�ڲ���Ԫ��
    int rangeL = 0;
    int rangeR = n - 1;

    while (rangeL <= rangeR) {
        //int mid = (rangeL + rangeR)/2;
        // ��ֹ��������µ����������ʹ��������߼����mid
        int mid = (rangeR - rangeL) / 2 + rangeL;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            //������[rangeL, mid - 1]��Χ�ڵ�Ԫ��
            rangeR = mid - 1;
        }
        else {
            //������[mid + 1, rangeR]��Χ�ڵ�Ԫ��
            rangeL = mid + 1;
        }
    }

    return -1;
}

// �õݹ�ķ�ʽд���ֲ��ҷ�
template<typename T>
int binarySearch2(T arr[], int n, T target) {
    return _binarySearch2(arr, 0, n - 1, target);
}

//��[rangeL, rangeR]��Χ�ڲ���Ԫ��
template<typename T>
int _binarySearch2(T arr[], int rangeL, int rangeR, T target) {
    if (rangeL > rangeR) {
        return -1;
    }

    //int mid = (rangeL+rangeR)/2;
    // ��ֹ��������µ����������ʹ��������߼����mid
    int mid = (rangeR - rangeL) / 2 + rangeL;

    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        //������[rangeL, mid - 1]��Χ�ڵ�Ԫ��
        return _binarySearch2(arr, rangeL, mid - 1, target);
    }
    else {
        //������[mid + 1, rangeR]��Χ�ڵ�Ԫ��
        return _binarySearch2(arr, mid + 1, rangeR, target);
    }
}

// ���ֲ��ҷ�, ����������arr��, ����target
// ����ҵ�target, ���ص�һ��target��Ӧ������index
// ���û���ҵ�target, ���ر�targetС�����ֵ��Ӧ������, ���������ֵ�ж��, �����������
// ������target�������������СԪ��ֵ��ҪС, �򲻴������target��floorֵ, ����-1
template<typename T>
int binarySearchFloor(T arr[], int n, T target) {
    assert(n >= 0);

    // Ѱ�ұ�targetС���������
    int rangeL = -1; //������target�������������СԪ��ֵ��ҪС, �򲻴������target��floorֵ, ����-1
    int rangeR = n - 1;
    while (rangeL < rangeR) {
        // ʹ������ȡ��������ѭ��
        int mid = rangeL + (rangeR - rangeL + 1) / 2;
        if (arr[mid] >= target)
            rangeR = mid - 1;
        else
            rangeL = mid;  //ע�ⲻ��mid+1����Ϊ��������ʱ����ҪȡtargetС�����ֵ��Ӧ������
    }

    assert(rangeL == rangeR);

    // ���������+1����target����, ������+1��Ϊ����ֵ
    if (rangeL + 1 < n && arr[rangeL + 1] == target)
        return rangeL + 1;

    // ����, ��������Ϊ����ֵ
    return rangeL;
}

// ���ֲ��ҷ�, ����������arr��, ����target
// ����ҵ�target, �������һ��target��Ӧ������index
// ���û���ҵ�target, ���ر�target�����Сֵ��Ӧ������, ��������Сֵ�ж��, ������С������
// ������target��������������Ԫ��ֵ��Ҫ��, �򲻴������target��ceilֵ, ������������Ԫ�ظ���n
template<typename T>
int binarySearchCeil(T arr[], int n, T target) {
    assert(n >= 0);

    // Ѱ�ұ�target�����С����
    int rangeL = 0;
    int rangeR = n; //������target��������������Ԫ��ֵ��Ҫ��, �򲻴������target��ceilֵ, ������������Ԫ�ظ���n
    while (rangeL < rangeR) {
        // ʹ������ȡ��������ѭ��
        int mid = rangeL + (rangeR - rangeL ) / 2;
        if (arr[mid] <= target)
            rangeL = mid + 1;
        else  // arr[mid] > target
            rangeR = mid; //ע�ⲻ��mid-1����Ϊ��������ʱ����Ҫ��target�����Сֵ��Ӧ������
    }

    assert(rangeL == rangeR);

    // ���������-1����target����, ������-1��Ϊ����ֵ
    if (rangeR - 1 < n && arr[rangeR - 1] == target)
        return rangeR - 1;

    // ����, ��������Ϊ����ֵ
    return rangeR;
}
