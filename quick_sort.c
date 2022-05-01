#include <stdio.h>

int partition(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);
void swap(int *a, int *b);

int main()
{
    int test_case[10] = {-15, 5, -12, 1, 0 , -1, -2, -3, -4, -5};
    int size = sizeof(test_case) / sizeof(test_case[0]);
    quick_sort(test_case, 0, size - 1);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", test_case[i]);
    }

    return 0;
}

void quick_sort(int arr[], int left, int right)
{
    int pivot;
    if (left < right)
    {
        pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivotIndex = low;
    int pivotValue = arr[high];
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(&arr[i], &arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(&arr[pivotIndex], &arr[high]);
    return pivotIndex;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
