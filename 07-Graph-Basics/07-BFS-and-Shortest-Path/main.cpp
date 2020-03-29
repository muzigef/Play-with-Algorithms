#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Path.h"
#include "ShortestPath.h"

// ������Ȩͼ���·���㷨
int main() {
    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();

    // �Ƚ�ʹ��������ȱ����͹�����ȱ������·���Ĳ�ͬ
    // ������ȱ�����õ�����Ȩͼ�����·��
    Path<SparseGraph> dfs(g, 0);
    cout << "DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout << "BFS : ";
    bfs.showPath(6);

    cout << endl;

    filename = "testG1.txt";
    SparseGraph g2 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename);
    g2.show();

    // �Ƚ�ʹ��������ȱ����͹�����ȱ������·���Ĳ�ͬ
    // ������ȱ�����õ�����Ȩͼ�����·��
    Path<SparseGraph> dfs2(g2, 0);
    cout << "DFS : ";
    dfs2.showPath(3);

    ShortestPath<SparseGraph> bfs2(g, 0);
    cout << "BFS : ";
    bfs2.showPath(3);

    system("pause");
    return 0;
}