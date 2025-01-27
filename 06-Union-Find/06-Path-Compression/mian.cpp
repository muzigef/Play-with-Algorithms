#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

// 测试UF1
int main() {

    // 使用10000的数据规模
    int n = 10000000;

    // 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
    // 总体测试过程的算法复杂度是O(n^2)的
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