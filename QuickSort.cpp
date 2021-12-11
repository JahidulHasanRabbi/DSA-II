#include<iostream>

using namespace std;

int Partition(int A[], int L, int R)
{
    int x = A[R];
    int i = L-1;

    for(int j=L; j<R; j++) {
        if(A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[R]);

    return i+1;
}

void quickSort(int A[], int L, int R)
{
    if(L < R)
    {
        int Part = Partition(A, L, R);

        quickSort(A, L, Part-1);
        
        quickSort(A, Part+1, R);
    }
}

int main()
{
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int length = sizeof(A)/sizeof(A[0]);

    quickSort(A, 0, length);

    for(int i=0; i<length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}