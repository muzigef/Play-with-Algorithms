#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

// ����UF1
int main() {

    // ʹ��10000�����ݹ�ģ
    int n = 10000000;

    // ��ȻisConnectedֻ��ҪO(1)��ʱ��, ������union������ҪO(n)��ʱ��
    // ������Թ��̵��㷨���Ӷ���O(n^2)��
    //UnionFindTestHelper::testUF1(n);
    //UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
    UnionFindTestHelper::testUF41(n);
    UnionFindTestHelper::testUF5(n);
    UnionFindTestHelper::testUF51(n);

    system("pause");
    return 0;
}