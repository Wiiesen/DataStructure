#include<iostream>

using namespace std;
const int INCRGAP = 2;

void shellSort(int a[], int len) {
    int insertNum = 0;
    unsigned gap = len / INCRGAP; // 步长初始化
    while (gap) // while gap>=1
    {
        for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];//将当前的元素值先存起来方便后面插入
            unsigned j = i;
            while (j >= gap && insertNum < a[j - gap])//寻找插入位置
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap / INCRGAP;
    }
}

int main() {
    int array[11] = {2, 1, 4, 3, 11, 6, 5, 7, 8, 10, 15};
    cout<<"原序："<<endl;
    for(int i=0;i<11;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"shell排序后:"<<endl;
    shellSort(array, 11);
    for (auto it: array) {
        cout << it << " ";
    }
    return 0;
}
