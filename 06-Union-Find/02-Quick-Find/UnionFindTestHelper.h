#pragma once

#include <iostream>
#include <ctime>
#include "UnionFind1.h"

using namespace std;

// ���Բ��鼯�ĸ�������
namespace UnionFindTestHelper {
    // ���Ե�һ�汾�Ĳ��鼯, ����Ԫ�ظ���Ϊn
    void testUF1(int n) {

        srand(time(nullptr));
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        // ����n�β���, ÿ�����ѡ������Ԫ�ؽ��кϲ�����
        //�ò�����¼����Ӷ�ΪO(n^2)
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }
        // �ٽ���n�β���, ÿ�����ѡ������Ԫ��, ��ѯ�����Ƿ�ͬ��һ������
        //�ò�����¼����Ӷ�ΪO(n)
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        // ��ӡ�������2n�������ĺ�ʱ
        cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}