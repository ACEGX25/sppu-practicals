//Program 9 : Implement Heap sort to sort given set of values using min heap.

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int temp;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    int temp;
    buildMinHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[10], n, i;
    cout << "\n Enter number of elements to be sorted: ";
    cin >> n;
    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n\nGiven array is: " << endl;
    printArray(arr, n);

    heapSort(arr, n);

    cout << "\n\nSorted array is: \n";
    printArray(arr, n);

    return 0;
}

/* Output :
ashutosh@Ubuntu:~$ g++ exp9min.cpp
ashutosh@Ubuntu:~$ ./a.out

 Enter number of elements to be sorted: 8

 Enter elements: 11
45
65
25
858
99
77
45


Given array is: 
11 45 65 25 858 99 77 45 


Sorted array is: 
858 99 77 65 45 45 25 11 
*?
