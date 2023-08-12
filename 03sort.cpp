#include <iostream>
#include <time.h>
using namespace std;

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}
void bubblesort(int *a, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int main()
{
    int n;
    clock_t s1, s2, e1, e2;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    s1 = clock();
    insertionSort(arr, n);
    e1 = clock();
    cout << "(Insertion) Sorted Array: ";
    display(arr, n);
    cout << "Time taken for Insertion sort:" << (double)(e1 - s1)/CLOCKS_PER_SEC << " sec" << endl;
    s2 = clock();
    bubblesort(arr, n);
    e2 = clock();
    cout << "(Bubble) Sorted Array: ";
    display(arr, n);
    cout << "Time taken for Bubble sort: " << (double)(e2 - s2)/CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
