
#ifndef DATASTRUCTURE_ADJMATRIXGRAPH_H
#define DATASTRUCTURE_ADJMATRIXGRAPH_H
const int MaxSize = 10;
enum GRAPHFLAG {
    UNDGRAPH, DGRAPH
};

template<class T>
class AdjMatrixGraph {
public:
    AdjMatrixGraph(T a[], GRAPHFLAG flag, int n, int e);

    ~AdjMatrixGraph() = default;

    void DFSTraverse(int v);

    void BFSTraverse(int v);

    void printAdjMatrix();

private:
    T vertex[MaxSize]; //顶点信息
    int visited[MaxSize]{}; //顶点访问标识
    int arc[MaxSize][MaxSize]{}; //邻接矩阵，二维数组
    int vertexNum, arcNum; //顶点和边的个数
    GRAPHFLAG graphFlag; //有向图或无向图标识
    void resetVisitFlag();

    void DFST(int v);

    void BFST(int v);
};

#endif //DATASTRUCTURE_ADJMATRIXGRAPH_H
