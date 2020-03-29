#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

int main() {
    // ʹ������ͼ�Ĵ洢��ʽ��ȡtestG1.txt�ļ�
    string filename = "testG1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    cout << "test G1 in Sparse Graph:" << endl;
    g1.show();

    cout << endl;

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    cout << "test G1 in Dense Graph:" << endl;
    g2.show();

    cout << endl;

    // ʹ������ͼ�Ĵ洢��ʽ��ȡtestG2.txt�ļ�
    filename = "testG2.txt";
    SparseGraph g3(6, false);
    ReadGraph<SparseGraph> readGraph3(g3, filename);
    cout << "test G2 in Sparse Graph:" << endl;
    g3.show();

    cout << endl;

    DenseGraph g4(6, false);
    ReadGraph<DenseGraph> readGraph4(g4, filename);
    cout << "test G2 in Dense Graph:" << endl;
    g4.show();

    system("pause");
    return 0;
}