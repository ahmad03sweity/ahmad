#include <iostream>
#include <cstdio>
#include <algorithm>
#include <chrono>

using namespace std;

clock_t startTime;
double getTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

//swap fn
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble sort 
void Bubblesort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


//selection sort
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }


        swap(&arr[min_idx], &arr[i]);
    }
}


//Insertion sort 
void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}


void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }

}

//Quik sort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

//Merge sort
void Merge(int arr[], int p, int q, int r)
{
    int a[100];
    int s = p, t = q + 1, k = p;
    while (s <= q && t <= r)
    {
        if (arr[s] <= arr[t])
        {
            a[k] = arr[s];
            s = s + 1;
        }
        else
        {
            a[k] = arr[t];
            t = t + 1;
        }
        k = k + 1;
    }
    if (s == q + 1)
    {
        for (; k <= r; k++)
        {
            a[k] = arr[t++];
        }
    }
    else
    {
        for (; k <= r; k++)
        {
            a[k] = arr[s++];
        }
    }
    for (; p <= r; p++)
    {
        arr[p] = a[p];
    }
}


int32_t main() {
    startTime = clock();
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;

    }
    quickSort(arr, 0, 99);
    cout << "quick  " << getTime() << endl;
    SelectionSort(arr, 100);
    cout << "selection  " << getTime() << endl;
    Bubblesort(arr, 100);
    cout << "bubble  " << getTime() << endl;
    InsertionSort(arr, 100);
    cout << "insertion  " << getTime() << endl;
    MergeSort(arr, 0, 99);
    cout << "merge " << getTime() << endl;
    return 0;
}