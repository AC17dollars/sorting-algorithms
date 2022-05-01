#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int rand_num(int start, int end);
int random_sort(int arr[], int size);

int main(){
    srand(time(NULL));

    int test_case[10] = {-15, 5, -12, 1, 0 , 9, 2, -1, -2, -3};

    while(!random_sort(test_case, 10));
    
    for(int i = 0; i < 10; i++){
        i == 9 ? printf("%d", test_case[i]) : printf("%d, ", test_case[i]);
    }

}
//the sorting algorithm; returns 1 if sorted; returns 0 if not sorted
int random_sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int j = rand_num(i, size);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1])           // check for ascending sort
            return 0;
    }
    return 1;
}

//random number generator
int rand_num(int start, int end){
    if(start == end)
        return end;
    else
        return rand()%(end-start) + (start < end ? start : end);
}