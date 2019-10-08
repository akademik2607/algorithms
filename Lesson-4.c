#include<stdio.h>
#define X 3
#define Y 3
void PrintArr(int arr[Y][X], int x, int y){
    for (int i = 0;i < y;i++){
        for(int j = 0; j < x; j++)
            printf("%d ",arr[i][j]);
    printf("\n");
    }
}
/*1. *Количество маршрутов с препятствиями.
 * Реализовать чтение массива с препятствием и нахождение количество маршрутов.*/
int Paths(int arr[Y][X], int x, int y){
    int arrN[y][x];
    for(int i = 0;i < x ; i++)
        arrN[0][i] = (arr[y][i] < 0) ? 0 : 1;

    for(int i = 0;i < y; i++)
        arrN[i][0] = (arr[i][x] < 0) ? 0 : 1;

    for (int i = 1;i < y;i++) {
        for (int j = 1;j < x;j++) {
            arrN[i][j] = (arr[i][j] < 0) ? 0 :  arrN[i - 1][j] + arrN[i][j - 1];
        }
    }
    return arrN[y - 1][x - 1];
}
int main(int args, char* argc[]){
    int arr[Y][X] = {{0, 0, -1}, {0, 0, 0}, {0, 0, 0}};
    PrintArr(arr, X, Y);
    printf("\n");
    printf("%d paths.", Paths(arr, X, Y));
    return 0;
}
