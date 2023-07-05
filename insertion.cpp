#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;

void insertion(int arr[], int size)
{
    for (int i=1; i<size; i++)
    {
        int key = arr[i], j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[MAX], size, i;
    clock_t start, end;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter elements: ";
    for (i=0;i<size;i++)
        cin >> arr[i];
    start = clock();
    insertion(arr,size);
    end = clock();
    cout << "The sorted array is: " << endl;
    for (i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << double(end-start)/CLOCKS_PER_SEC << endl;
    return 0;
}