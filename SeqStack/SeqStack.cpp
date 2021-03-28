#include "SeqStack.h"
using namespace std;
template <class T>
SeqStack<T>::SeqStack() {
    top=-1;
}
template <class T>
SeqStack<T>::~SeqStack<T>() {}
template <class T>
void SeqStack<T>::Push(T x)
{
    if (top == StackSize-1) throw "上溢";
    top++;
    data[top]=x;
}
template <class T>
T SeqStack<T>::Pop( )
{
    T x;
    if (top==-1) throw "下溢";
    x=data[top--];
    return x;
}
template <class T>
T SeqStack<T>::GetTop( )
{
    if (top==-1) throw "栈为空";
    else return data[top];
}
template <class T>
bool SeqStack<T>::Empty( )
{
    if(top==-1) return true;
    else return false;
}