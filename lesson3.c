#include <stdio.h>
#define ARR_LENGTH 10
void printArray(int* arr, int length){
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}
void swap(int *a, int *b){
    if(*a != * b){
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
/*1. Попробовать оптимизировать пузырьковую сортировку.
Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
Написать функции сортировки, которые возвращают количество операций.*/
int boobleSort(int* arr, int length){
    int operations = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            operations++;
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
    return operations;
}
int boobleSortOpt(int* arr, int length){
    int operations = 0;
    int arrIters = length;
    for(int i = 0; i < length; i++){
        arrIters--;
        for(int j = 0; j < arrIters; j++){
            operations++;
            if(arr[j] > arr[j + 1])swap(&arr[j], &arr[j + 1]);
        }
    }
    return operations;
}
/*2. Реализовать шейкерную сортировку.*/
int shakerSort(int* arr, int length){
    int max = length;
    int min = 0;
    int operations = 0;
    while(max != min){
    for(int i = 0; i < max; i++){
        operations++;
        if(arr[i] > arr[i + 1]) swap(&arr[i], &arr[i + 1]);
    }
    max--;
    if(max == min) break;
    for(int i = max; i > min; i--){
        operations++;
        if(arr[i] < arr[i - 1]) swap(&arr[i], &arr[i - 1]);
    }
    min++;
    }
    return operations;
}
/*3 optional. Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.*/
void PigeonHoleSort(int* arr1, int* arr2, int* arr3, int len, int k){
    for(int i = 0; i < len; i++){
        for (int j = 0;j < k; j++){
            if(arr1[i] == j)
                arr3[j]++;
        }
        }
        for (int i = 1; i < k ; i++)
            arr3[i] = arr3[i] + arr3[i - 1];

        for (int i = k; i >= 0 ; i--){
            for(int j = 0; j < k; j++){
                if(arr1[i] == j){
                    arr2[arr3[j] - 1] = arr1[i];
                    arr3[j]--;
                }
            }
        }
      }

int main(){
//1.
    int arr1[ARR_LENGTH];
    int arr2[ARR_LENGTH];
    for(int i = 0, j = ARR_LENGTH; i < ARR_LENGTH; i++, j--)
        arr1[i] = arr2[i] = j;
    printArray(arr1, ARR_LENGTH);
    printf("\n");
    printArray(arr2, ARR_LENGTH);
    printf("\n\n");
    int operations1 = boobleSort(arr1, ARR_LENGTH);
    int operations2 = boobleSortOpt(arr2, ARR_LENGTH);
    printArray(arr1, ARR_LENGTH);
    printf("\noperations = %d", operations1);
    printf("\n");
    printArray(arr2, ARR_LENGTH);
    printf("\noperations = %d", operations2);
//2.
    for(int i = 0, j = ARR_LENGTH; i < ARR_LENGTH; i++, j--)
        arr1[i] = j;
    printf("\n\n");
    printArray(arr1, ARR_LENGTH);
    printf("\n");
    int operations3 = shakerSort(arr1, ARR_LENGTH);
    printArray(arr1, ARR_LENGTH);
    printf("\noperations = %d", operations3);
//3.
    int arr3[ARR_LENGTH];
    for(int i = 0, j = ARR_LENGTH; i < ARR_LENGTH; i++, j--)
        arr1[i] = j - 1;
    for(int i = 0; i < ARR_LENGTH; i++){
        arr2[i] = 0;
        arr3[i] = 0;
    }
    printf("\n\n");
    printArray(arr1, ARR_LENGTH);
    printf("\n");
    printArray(arr1, ARR_LENGTH);
    PigeonHoleSort(arr1, arr2, arr3, ARR_LENGTH, ARR_LENGTH);
    printf("\n");
    printArray(arr2, ARR_LENGTH);
    return 0;
}
