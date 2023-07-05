#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;

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
    int flag = lin(arr,size,elem);
    end = clock();
    if (flag == -1)
        cout << "Element not found";
    else
        cout << "Element found at index: " << flag;
    cout << "Time taken: " << double(end-start)/CLOCKS_PER_SEC << endl;
    return 0;
}