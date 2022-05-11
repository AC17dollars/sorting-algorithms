#include <stdio.h>

void merge_sort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

int main(){
    int test_case[] = {6,5,1,2,8,4,5,9,10};
    int size = sizeof(test_case) / sizeof(test_case[0]);
    merge_sort(test_case, 0, size - 1);

    for(int i=0; i<size; i++){
        printf("%d, ", test_case[i]);
    }
    return 0;
}

void merge_sort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int arr[], int start, int mid, int end){
    int temp[end-start+1];

    //to traverse the two splitted array i, j and to traverse temp array; k 
    int i = start; 
    int j = mid + 1;
    int k = 0;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++; i++;
        }
        else{
            temp[k] = arr[j];
            k++; j++;
        }
    }

    //if one of the spilitted side is finished copy the first one first
    while(i<=mid){
        temp[k] = arr[i];
        k++; i++;
    }
    //copy the second one later
    while(j<=end){
        temp[k] = arr[j];
        k++; j++;
    }
    //copy temp to the actual array
    for(int i = start; i <= end; i++){
        arr[i] = temp[i-start];
    }
}
