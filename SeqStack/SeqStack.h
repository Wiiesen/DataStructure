
#ifndef DATASTRUCTURE_SEQSTACK_H
#define DATASTRUCTURE_SEQSTACK_H
const int StackSize=10;
template <class T>
class SeqStack{
public:
    SeqStack();
    ~SeqStack();
    void Push(T x);
    T Pop();
    T GetTop();
    bool Empty();

private:
    T data[StackSize];
    int top;
};
#endif //DATASTRUCTURE_SEQSTACK_H
