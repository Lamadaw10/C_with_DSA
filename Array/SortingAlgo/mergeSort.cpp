//Merge Sorting Algorithm Implementation
#include <iostream>
using namespace std;

//Function to implement the merge sorting algorithm
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    //Temporary arrays
    int a[n1];
    int b[n2];

    for(int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for(int j = 0; j < n2; j++)
    {
        b[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++; 
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while(i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

//Function to perform merge sort
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = (l + r)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}