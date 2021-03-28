#include <iostream>

void BubbleSort(int arr[], int n);

void InverseBubbleSort(int arr[], int n);

void printArray(int arr[], int n);

void aprint(int *arr);

const int n = 8;

int main(int argc, char **argv) {
    std::cout << "原序：\n";
    int a[n] = {6, 5, 3, 1, 8, 7, 2, 4};
    aprint(a);
    BubbleSort(a, n);
    std::cout << "\n";
    std::cout << "从小到大的冒泡排序:\n";
    printArray(a, n);
    int b[n] = {6, 5, 3, 1, 8, 7, 2, 4};
    InverseBubbleSort(b, n);
    std::cout << "从大到小的冒泡排序:\n";
    printArray(b, n);
    return 0;
}

void aprint(int *arr) {
    for (int i = 0; i < n - 1; i++) {
        std::cout << arr[i] << " ";
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void InverseBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}