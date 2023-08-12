#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;

void merge(int arr[], int low, int high, int mid)
{
    int i=low, k=0, j=mid+1, temp[high-low+1];
    while (i<=mid && j<=high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i<=mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int arr[MAX], size;
    clock_t start, end;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter elements: ";
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    start = clock();
    mergeSort(arr,0,size-1);
    end = clock();
    cout << "The sorted array is: " << endl;
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << double(end-start)/CLOCKS_PER_SEC << endl;
    return 0;
}
