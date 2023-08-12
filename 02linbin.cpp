#include <iostream>
#include <time.h>
using namespace std;

#define MAX 20

int lin(int arr[], int n, int key)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (arr[i]==key)
            return i;
    }
    return -1;
}

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
    clock_t s1, s2, e1, e2;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter elements: ";
    for (i=0;i<size;i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> elem;
    // Linear Search
    s1 = clock();
    int flag1 = lin(arr,size,elem);
    if (flag1 == -1)
        cout << "(Linear) Element not found" << endl;
    else
        cout << "(Linear) Element found at index: " << flag1 << endl;
    e1 = clock();
    // Binary Search
    s2 = clock();
    int flag2 = lin(arr,size,elem);
    if (flag2 == -1)
        cout << "(Binary) Element not found" << endl;
    else
        cout << "(Binary) Element found at index: " << flag2 << endl;
    e2 = clock();
    cout << "Linear search: " << double(e1-s1)/CLOCKS_PER_SEC << endl;
    cout << "Binary search: " << double(e2-s2)/CLOCKS_PER_SEC << endl;
    return 0;
}
