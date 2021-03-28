
#ifndef SeqList_H
#define SeqList_H

template<class T>
struct BiNode {
    T data;
    BiNode<T> *lchild, *rchild;
};


template<class T>
class BiTree {
public:
    BiTree();
    ~BiTree() { Release(root); }

    void PreOrder() { PreOrder(root); }

    void InOrder() { InOrder(root); }

    void PostOrder() { PostOrder(root); }

    void LeverOrder();

private:
    BiNode<T> *root;

    BiNode<T> *Creat(BiNode<T> *bt);

    BiNode<T> *Creat(BiNode<T> *bt, char direct, int &lev, T chr);

    void Release(BiNode<T> *bt);

    void PreOrder(BiNode<T> *bt);

    void InOrder(BiNode<T> *bt);

    void PostOrder(BiNode<T> *bt);
};

#endif