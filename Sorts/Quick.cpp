#include<iostream>

using namespace std;

void quickSort(int a[], int m, int n);

int partion(int a[], int m, int n);

int main() {
    int a[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    cout<<"Ô­Ðò:"<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int m = 0;
    int n = (sizeof(a) / 4) - 1;
    quickSort(a, m, n);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
}

void quickSort(int a[], int m, int n) {
    if (m < n) {
        int q = partion(a, m, n);
        quickSort(a, m, q);
        quickSort(a, q + 1, n);
    }
}

int partion(int a[], int m, int n) {
    int key = m;
    int j = n, i = m;
    int temp1, temp2;
    while (i != j) {
        while (a[j] > a[key] && i < j) {
            --j;
        }

        while ((a[i] < a[key]) && (i < j)) {
            ++i;
        }
        if (i < j) {
            temp1 = a[j];
            a[j] = a[i];
            a[i] = temp1;
        }
    }
    temp2 = a[key];
    a[key] = a[i];
    a[i] = temp2;
    return i;
}

