#include<iostream>
using namespace std;

void print(int a[], int n)
{
    for(int j= 0; j<n; j++)
    {
        cout<<a[j] <<"  ";
    }
    cout<<endl;
}

void selectSort(int a[], int len)
{

    int minindex, temp;
    for(int i = 0; i<len-1;i++)
    {
        minindex = i;
        for(int j = i+1; j<len; j++)
        {
            if(a[j]<a[minindex])
                minindex = j;

        }
        temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }
}

int main()
{
    int a[10] = {8,1,9,7,2,4,5,6,10,3};
    cout<<"初始序列：";
    print(a,10);
    selectSort(a,10);
    cout<<"排序结果：";
    print(a,10);
    system("pause");
}