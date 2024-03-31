#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int N, int i) {
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if((l < N) && (arr[l] > arr[largest])) {
        largest = l;
    }

    if((r < N) && (arr[r] > arr[largest])) {
        largest = r;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int *arr, int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for(int i = N-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);

    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}
