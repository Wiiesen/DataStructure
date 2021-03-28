#include <iostream>
#include "SeqList.h"
using namespace std;
//无参构造函数初始化顺序表
template <class T>
SeqList<T>::SeqList(){
    length=0;
}
//有参构造函数
template <class T>
SeqList<T>::SeqList(T a[],int n){
    if(n>MaxSize)throw "非法参数";
    for(int i=0;i<n;i++){
        data[i] = a[i];
    }
    length=n;
}
//析构函数
template <class T>
SeqList<T>::~SeqList() {}
//插入元素x到顺序表中位置i处
template <class T>
void SeqList<T>::Insert(int i, T x) {
    if(length==MaxSize)throw"上溢";
    if(i<1||i>length+1)throw"位置";
    for(int j=length;j>=i;j--){
        data[j]=data[j-1];
        data[i-1]=x;
    }
    length++;
}
//删除顺序表中位置为i的元素
template <class T>
T SeqList<T>::Delete(int i) {
    T x;
    if(length==0)throw "下溢";
    if(i<1||i>length)throw "位置";
    x=data[i-1];
    for(int j=i;j<=length-1;j++){
        data[j-1]=data[j];
        length--;
    }
    return x;
}
//获取顺序表长度
template <class T>
int SeqList<T>::Length() {
    return length;
}
//查找元素位置
template <class T>
T SeqList<T>::Get(int i) {
    if(i<1||i>length)throw "查找位置非法";
    else return data[i-1];
}
//按值查找元素并输出位置
template <class T>
int SeqList<T>::Locate(T x) {
    for(int i=0;i<length-1;i++){
        if(data[i]==x){
            return i+1;
        }
    }
    return 0;
}
//循环输出
template <class T>
void SeqList<T>::PrintList(){
    for(int i=0;i<length;i++){
        cout<<data[i]<<endl;
    }
}