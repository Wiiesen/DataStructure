#include <iostream>
#include "AdjMatrixGraph.cpp"
#include <string>

using namespace std;

int main() {
    cout << "**************************" << endl
         << "无向图:" << endl
         << "**************************" << endl;
    int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    AdjMatrixGraph<int> grapA(a, UNDGRAPH, 8, 6);
    grapA.DFSTraverse(0);
    grapA.BFSTraverse(0);
    grapA.printAdjMatrix();
    cout << "**************************" << endl
         << "有向图:" << endl
         << "**************************" << endl;
    int b[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    AdjMatrixGraph<int> grapB(b, DGRAPH, 8, 8);
    grapB.DFSTraverse(0);
    grapB.BFSTraverse(0);
    grapB.printAdjMatrix();
    system("pause");
    return 0;
}