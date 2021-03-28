#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H
template <class T>
struct Node{
    T data;
    Node<T> *next;
};

template <class T>
class LinkList{
public:
    LinkList();
    LinkList(T a[],int n);
    ~LinkList();
    int Length();
    T Get(int i);
    int Locate(T x);
    void Insert(int i,T x);
    T Delete(int i);
    void PrintList();
private:
    Node<T> *first;
};
#endif //DATASTRUCTURE_LINKLIST_H
