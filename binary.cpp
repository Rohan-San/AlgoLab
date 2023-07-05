#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;

int bin(int arr[], int key, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid+1;
        if (arr[mid] > key)
            right = mid-1;            
    }
    return -1;
}

int main()
{
    int arr[MAX], size, i, elem;
    clock_t start, end;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter elements: ";
    for (i=0;i<size;i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> elem;
    start = clock();
    int flag = bin(arr,elem,0,size-1);
    end = clock();
    if (flag == -1)
        cout << "Element not found";
    else
        cout << "Element found at index: " << flag;
    cout << "Time taken: " << double(end-start)/CLOCKS_PER_SEC << endl;
    return 0;
}