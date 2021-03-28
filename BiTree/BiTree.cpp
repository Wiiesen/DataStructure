
#include "BiTree.h"
#include <iostream>

using namespace std;


template<class T>
BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt) {
    //char ch;
    T ch;
    cout << "请输入创建一棵二叉树的结点数据" << endl;
    cin >> ch;
    if (ch == '#') return NULL;
    else {
        bt = new BiNode<T>;       //生成一个结点
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);    //递归建立左子树
        bt->rchild = Creat(bt->rchild);    //递归建立右子树
    }
    return bt;

}

template<class T>
BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt, char direct, int &lev, T chr) {
    //char ch;
    T ch;

    cout << "请输入创建一棵二叉树的" << chr << " " << direct << lev << "结点数据" << endl;
    cin >> ch;
    if (ch == '#') return NULL;
    else {
        bt = new BiNode<T>;       //生成一个结点
        bt->data = ch;
        bt->lchild = Creat(bt->lchild, 'L', ++lev, ch);    //递归建立左子树
        bt->rchild = Creat(bt->rchild, 'R', lev, ch);    //递归建立右子树
        lev--;
    }
    return bt;

}

template<class T>
void BiTree<T>::Release(BiNode<T> *bt) {
    if (bt != NULL) {
        Release(bt->lchild);   //释放左子树
        Release(bt->rchild);   //释放右子树
        delete bt;
    }

}


template<class T>
void BiTree<T>::PreOrder(BiNode<T> *bt) {
    if (bt == NULL) return;
    else {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

template<class T>
void BiTree<T>::InOrder(BiNode<T> *bt) {
    if (bt == NULL) return;      //递归调用的结束条件
    else {
        InOrder(bt->lchild);    //中序递归遍历root的左子树
        cout << bt->data << " ";    //访问根结点的数据域
        InOrder(bt->rchild);    //中序递归遍历root的右子树
    }
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T> *bt) {
    if (bt == NULL) return;       //递归调用的结束条件
    else {
        PostOrder(bt->lchild);    //后序递归遍历root的左子树
        PostOrder(bt->rchild);    //后序递归遍历root的右子树
        cout << bt->data << " ";      //访问根结点的数据域
    }
}

template<class T>
void BiTree<T>::LeverOrder() {
    const int MaxSize = 100;
    int front = -1, rear = -1;  //采用顺序队列，并假定不会发生上溢
    BiNode<T> *Q[MaxSize], *q;
    if (root == NULL) return;
    else {
        Q[++rear] = root;
        while (front != rear) {
            q = Q[++front];
            cout << q->data << " ";
            if (q->lchild != NULL) Q[++rear] = q->lchild;
            if (q->rchild != NULL) Q[++rear] = q->rchild;
        }
    }
}


template<class T>
BiTree<T>::BiTree() {
    int start = 0;
    root = Creat(root);
//ot=Creat(root,'L',start,'@');

}