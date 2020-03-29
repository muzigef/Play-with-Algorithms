#include "BinarySearch.h"
#include <ctime>


int main() {
    /*===============================================================================================
     �ȽϷǵݹ�͵ݹ�д���Ķ��ֲ��ҵ�Ч��
     �ǵݹ��㷨����������΢������
    ==================================================================================================*/

    /*int n = 1000000;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;

    // ���Էǵݹ���ֲ��ҷ�
    clock_t startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


    // ���Եݹ�Ķ��ֲ��ҷ�
    startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    delete[] a;*/

    /*===============================================================================================
     ���������ö��ֲ��ҷ�ʵ�ֵ�floor��ceil��������
     ����ϸ�۲������ǵĲ��������У������ɵ��ظ�Ԫ�أ�������Щ�ظ�Ԫ�أ�floor��ceil�����������𣺣�
    ==================================================================================================*/
    int a[] = { 1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6 };
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i <= 8; i++) {

        int floorIndex = binarySearchFloor(a, n, i);
        cout << "the floor index of " << i << " is " << floorIndex << ".";
        if (floorIndex >= 0 && floorIndex < n)
            cout << "The value is " << a[floorIndex] << ".";
        cout << endl;

        int ceilIndex = binarySearchCeil(a, n, i);
        cout << "the ceil index of " << i << " is " << ceilIndex << ".";
        if (ceilIndex >= 0 && ceilIndex < n)
            cout << "The value is " << a[ceilIndex] << ".";
        cout << endl;

        cout << endl;
    }

    system("pause");
    return 0;
}