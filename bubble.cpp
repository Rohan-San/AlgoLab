#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;

void bubble(int arr[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubble(arr,size);
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