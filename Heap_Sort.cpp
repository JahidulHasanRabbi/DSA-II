#include<iostream>

using namespace std;

void Max_Heapify(int A[], int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;

    int largest = i;

     if(l < n && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if(r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        Max_Heapify(A, largest, n);
    }

}

void Build_Max_Heap(int A[], int n) 
{
    for(int i=(n/2); i>=0; i--) {
        Max_Heapify(A, i, n);
    }

 }

void heapSort(int A[], int n)
{
    Build_Max_Heap(A, n);

    for(int i=n; i>=0; --i) {
        swap(A[0], A[i]);
       
        Max_Heapify(A, 0, i);
    }
}

int main()
{
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = sizeof(A)/sizeof(A[0]);
    cout << length << endl;

    heapSort(A, length-1);

    for(int i=0; i<length; i++) {
        cout << A[i] << " ";
    }

    return 0;
}