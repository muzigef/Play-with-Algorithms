#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"

int main() {
    int N = 20;
    int M = 100;

    srand(time(nullptr));


    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; i++) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    // O(E)
    for (int v = 0; v < N; v++) {
        cout << v << " : ";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    // Dense Graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; i++) {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }

    // O(V^2)
    for (int v = 0; v < N; v++) {
        cout << v << " : ";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}