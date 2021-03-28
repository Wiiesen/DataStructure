#include <iostream>
#include "SeqList.cpp"
using namespace std;
int main(){
    SeqList<int> a;
    cout<<"执行插入操作:"<<endl;
    try{
        a.Insert(1,1);
        a.Insert(2,3);
        a.Insert(3,4);
    }
    catch (char* wrong) {
        cout<<wrong;
    }
    cout<<"已经插入\"1，3，5\""<<endl;
    cout<<endl;
    cout<<"顺序表a的长度为:";
    cout<<a.Length()<<endl;
    cout<<endl;
    cout<<"按位查询第二个元素:"<<endl;
    cout<<a.Get(2)<<endl;
    cout<<endl;
    cout<<"按值查询3:"<<endl;
    cout<<"值为3的元素位置为:";
    cout<<a.Locate(3)<<endl;
    cout<<endl;
    try {
        if(a.Length()){
            cout<<"执行删除第一个元素的操作:"<<endl;
            cout<<endl;
            a.Delete(1);
            cout<<"已经删除成功，顺序表a的长度为:";
            cout<<a.Length()<<endl;
        } else{
            cout<<"顺序表长度为0!"<<endl;
        }
    }
    catch (char* wrong) {
        cout<<wrong;
    }
    cout<<endl;
    cout<<"顺序表a中的元素有:"<<endl;
    a.PrintList();

    int r[]={1,2,3,4,5};
    SeqList<int>b(r,5);
    cout<<"执行插入操作前顺序表b为:"<<endl;
    b.PrintList();
    cout<<"插入前顺序表b的长度为:";
    cout<<b.Length()<<endl;
    try{
        b.Insert(3,8);
    }
    catch (char* wrong) {
        cout<<wrong;
    }
    cout<<"执行插入操作后顺序表b为:"<<endl;
    b.PrintList();
    cout<<"插入后顺序表b的长度为:";
    cout<<b.Length()<<endl;
    cout<<endl;
    try{
        if(a.Length()){
            cout<<"执行删除第一个元素的操作:"<<endl;
            cout<<endl;
            b.Delete(1);
            cout<<"已成功删除，顺序表b的长度为:";
            cout<<b.Length()<<endl;
        } else{
            cout<<"顺序表b长度为0"<<endl;
        }
    }
    catch (char* wrong) {
        cout<<wrong;
    }
    cout<<"执行插入操作就顺序表b为:"<<endl;
    b.PrintList();
}