//Program 9 : Implement Heap sort to sort given set of values using max heap.

#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
   int temp;
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && arr[l] > arr[largest])
      largest = l;
   if (r < n && arr[r] > arr[largest])
      largest = r;
   if (largest != i) {
      temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}
void printarray(int arr[],int n)
   { int i;
     for (i = 0; i < n; ++i)
     cout<<arr[i]<<"   ";
     cout<<"\n";
}  
void heapSort(int arr[], int n) {
   int temp;
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   for (int i = n - 1; i >= 0; i--) {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
      printarray(arr,n);
   }
 }
 
 
int main() {
   int arr[10] ,n,i;
   cout<<"\n Enter number of elements to be sorted : ";
   cin>>n; 
   cout<<"\n Enter elements :";
   for(i=0;i<n;i++)
   cin>>arr[i];
   cout<<"\n\nGiven array is: "<<endl;
   for (i = 0; i<n; i++)
   cout<<arr[i]<<" ";
   cout<<endl;
   heapSort(arr, n);
   printf("\n\nSorted array is: \n");
   for (i = 0; i < n; ++i)
   cout<<arr[i]<<" ";
   cout<<endl;
}
/*
OUTPUT:-

ubuntu@ubuntu-OptiPlex-390:~$ g++ heapsort.cpp
ubuntu@ubuntu-OptiPlex-390:~$ ./a.out

 Enter number of elements to be sorted : 8

 Enter elements :11

45
65
25
858
99
77
45


Given array is: 
11 45 65 25 858 99 77 45 
99   45   77   25   45   65   11   858   
77   45   65   25   45   11   99   858   
65   45   11   25   45   77   99   858   
45   45   11   25   65   77   99   858   
45   25   11   45   65   77   99   858   
25   11   45   45   65   77   99   858   
11   25   45   45   65   77   99   858   
11   25   45   45   65   77   99   858   


Sorted array is: 
11 25 45 45 65 77 99 858 
ubuntu@ubuntu-OptiPlex-390:~$ 

*/
