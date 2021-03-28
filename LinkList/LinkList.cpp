#include <iostream>
#include "LinkList.h"
template <class T>
LinkList<T>::LinkList() {
    first=new Node<T>;
    first->next= nullptr;
}//无参构造函数,构建并初始化单链表
template <class T>
LinkList<T>::LinkList(T *a, int n) {
    first=new Node<T>;
    Node<T> *rear,*s;
    rear=first;
    for(int i = 0;i<n;i++){
        s=new Node<T>;
        s->data = a[i];
        rear->next = s;
        rear = s;
    }
    rear->next = nullptr;
}//有参构造函数，传入数组作为data的存储结构和创建单链表的长度
template <class T>
LinkList<T>::~LinkList() {}
//析构函数，自动释放内存
template <class T>
T LinkList<T>::Get(int i) {
    Node<T> *p=first->next;
    int j=1;
    while (p&&j<i){
        p=p->next;
        j++;
    }
    if (!p)throw "位置";
    else{
        return p->data;
    }
}//查询i位置元素的值
template <class T>
int LinkList<T>::Locate(T x) {
    Node<T> *p=first->next;
    int j=1;
    if(p&&p->next){
        while (p->data!=x){
            p=p->next;
            j++;
        }
        return j;
    }
    else throw "位置";
}//查询元素位置并输出所在位置
template <class T>
void LinkList<T>::Insert(int i, T x) {
    Node<T> *p; int j;
    p=first ; j=0;    //工作指针p初始化
    while (p && j<i-1)
    {
        p=p->next;   //工作指针p后移
        j++;
    }
    if (!p) throw "位置";
    else {
        Node<T> *s;
        s=new Node<T>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}//在i位置插入一个节点
template <class T>
int LinkList<T>::Length( )
{
    Node <T> *p = first->next;
    int i = 0;
    while(p)
    {
        p = p->next;
        i++;
    }
    return i;
}//获取单链表长度
template <class T>
T LinkList<T>::Delete(int i)
{
    Node<T> *p; int j;
    p=first ; j=0;  //工作指针p初始化
    while (p && j<i-1)  //查找第i-1个结点
    {
        p=p->next;
        j++;
    }
    if (!p || !p->next) throw "位置";  //结点p不存在或结点p的后继结点不存在
    else {
        Node<T> *q; int x;
        q=p->next; x=q->data;  //暂存被删结点
        p->next=q->next;  //摘链
        delete q;
        return x;
    }
}//删除i处节点
template <class T>
void LinkList<T>::PrintList( )
{
    Node<T> *p;
    p=first->next;
    while (p)
    {
        std::cout<<p->data<<std::endl;
        p=p->next;
    }
}//打印单链表中所有信息

