//
// Created by y1029 on 2020/11/3.
//

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

const int MaxSize=100;
template <class T>
class SeqList{
public:
    SeqList();
    SeqList(T a[],int n);
    ~SeqList();
    int Length();
    T Get(int i);
    int Locate(T x);
    void Insert(int i,T x);
    T Delete(int i);
    void PrintList();
private:
    T data[MaxSize];
    int length{};
};
#endif //DATASTRUCTURE_SEQLIST_H
