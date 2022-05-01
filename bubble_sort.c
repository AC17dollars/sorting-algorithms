#include <stdio.h>

int bubble_sort(int arr[], int size);

int main(){
    int test_case[10] = {-15, 5, -12, 1, 0 , 9, 2, -1, -2, -3};

    bubble_sort(test_case, 10);
    
    for(int i = 0; i < 10; i++){
        i == 9 ? printf("%d", test_case[i]) : printf("%d, ", test_case[i]);
    }

}
//the sorting algorithm; returns 1 if sorted
int bubble_sort(int arr[], int size){
    for(int i = size; i > 0; i--){
        for(int j = 0; j < i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 1;
}