#include "AdjMatrixGraph.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
*前置条件：图不存在
*输 入：n 个顶点，e 条边
*功 能：图的初始化
*输 出：无
*后置条件：构造一个含有 n 个顶点 e 条边的图
*/
template<class T>
AdjMatrixGraph<T>::AdjMatrixGraph(T a[], GRAPHFLAG flag, int n, int e) {
    vertexNum = n;
    arcNum = e;
    graphFlag = flag;
    for (int i = 0; i < vertexNum; i++) {
        vertex[i] = a[i];
    }
    for (int i = 0; i < vertexNum; i++) //初始化邻接矩阵
        for (int j = 0; j < vertexNum; j++)
            arc[i][j] = 0;
    for (int k = 0; k < arcNum; k++) //依次输入每一条边
    {
        cout << "请输入图中边（弧）的两个邻接点：" << endl;
        int vi, vj;
        cin >> vi >> vj; //输入边依附的两个顶点的编号
        if (graphFlag == UNDGRAPH) {
            arc[vi][vj] = 1;
            arc[vj][vi] = 1; //置有边标志
        } else {
            arc[vi][vj] = 1; //置有边标志
        }
    }
}

/*
*前置条件：图已存在
*输 入：遍历的起始顶点 v
*功 能：从顶点 v 出发深度优先遍历图
*输 出：图的深度优先遍历序列
*后置条件：图保持不变
*/
template<class T>
void AdjMatrixGraph<T>::DFSTraverse(int v) {
    resetVisitFlag();
    DFST(v);
    for (int i = 0; i < vertexNum; ++i) {
        if (visited[i] == 0) {
            cout << "深度优先遍历出现非联通顶点！" << endl;
            DFST(i);
        }
    }
}

/*
*前置条件：图已存在
*输 入：遍历的起始顶点 v
*功 能：从顶点 v 出发深度优先遍历图
*输 出：图的深度优先遍历序列
*后置条件：图保持不变
*/
template<class T>
void AdjMatrixGraph<T>::DFST(int v) {
    cout << "深度优先遍历顶点：" << vertex[v] << endl;
    visited[v] = 1;
    for (int j = 0; j < vertexNum; j++)
        if (arc[v][j] == 1 && visited[j] == 0) DFST(j);
}

/*
*前置条件：图已存在
*输 入：遍历的起始顶点 v
*功 能：从顶点 v 出发广度优先遍历图
*输 出：图的广度优先遍历序列
*后置条件：图保持不变
*/
template<class T>
void AdjMatrixGraph<T>::BFSTraverse(int v) {
    resetVisitFlag();
    BFST(v);
    for (int i = 0; i < vertexNum; ++i) {
        if (visited[i] == 0) {
            cout << "广度优先遍历出现非联通顶点！" << endl;
            BFST(i);
        }
    }
}

/*
*前置条件：图已存在
*输 入：遍历的起始顶点 v
*功 能：从顶点 v 出发广度优先遍历图
*输 出：图的广度优先遍历序列
*后置条件：图保持不变
*/
template<class T>
void AdjMatrixGraph<T>::BFST(int v) {
    int Q[MaxSize];
    int front, rear;
    front = rear = -1; //初始化顺序队列
    cout << "广度优先遍历起始顶点：" << vertex[v] << endl;
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear) //当队列非空时
    {
        v = Q[++front]; //将队头元素出队并送到 v 中
        for (int j = 0; j < vertexNum; j++)
            if (arc[v][j] == 1 && visited[j] == 0) {
                cout << "广度优先遍历顶点：" << vertex[j] << endl;
                visited[j] = 1;
                Q[++rear] = j;
            }
    }
}

/*
*前置条件：图已存在
*输 入：无
*功 能：重置图中顶点访问标示
*输 出：无
*后置条件：图中所有顶点未被访问
*/
template<class T>
void AdjMatrixGraph<T>::resetVisitFlag() {
    for (int i = 0; i < vertexNum; i++) {
        visited[i] = 0;
    }
}

/*
*前置条件：图已存在
*输 入：无
*功 能：打印邻接矩阵
*输 出：无
*后置条件：无
*/
template<class T>
void AdjMatrixGraph<T>::printAdjMatrix() {
    for (int i = 0; i < vertexNum; ++i) {
        for (int j = 0; j < vertexNum; ++j) {
            cout << setw(3) << arc[i][j] << " ";
        }
        cout << endl;
    }
}