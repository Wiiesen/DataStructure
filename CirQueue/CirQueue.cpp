/*定义顺序队列的存储结构：（私有）数据封装（一维）数组
 * （存储数据元素，位置/下标表示数据元素之间的逻辑关系，不占用存储空间）、
 * 队头和队尾指针（整型变量，存储队头和队尾下标），队列的头尾在数组存储空间内循环移动；
 * 本次实现队列的对头指针的下一个位置存储表中第一个数据元素，队尾指针指向表中最后一个元素。
 */
#include "CirQueue.h"

//无参构造函数初始化队列（空）
template <class T>
CirQueue<T>::CirQueue( )
{
    front=rear=0;
}
//析构函数释放队列所占存储空间
template <class T>
CirQueue<T>::~CirQueue<T>() {}
//在对位插入一个元素
template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if ((rear+1) % QueueSize ==front) throw "上溢";
    rear=(rear+1) % QueueSize;   //队尾指针在循环意义下加1
    data[rear]=x;                //在队尾处插入元素
}
//删除队头元素
template <class T>
T CirQueue<T>::DeQueue( )
{
    if (rear==front) throw "下溢";
    front=(front+1) % QueueSize;     //队头指针在循环意义下加1
    return data[front];              //读取并返回出队前的队头元素，注意
}                                //队头指针指向队头元素的前一个位置
//读取队头元素
template <class T>
T CirQueue<T>::GetQueue( )
{
    int i;
    if (rear==front) throw "下溢";
    i=(front+1) % QueueSize;  //注意不要给队头指针赋值
    return data[i];
}
//判断队列是否为空
template <class T>
bool CirQueue<T>::Empty( )
{
    if (front==rear)
        return true;
    else
        return false;
}



