#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Path.h"

// ≤‚ ‘—∞¬∑À„∑®
int main() {
    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> path(g, 0);
    cout << "Path from 0 to 6 : " << endl;
    path.showPath(6);

    system("pause");
    return 0;
}