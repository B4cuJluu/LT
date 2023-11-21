#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 8

void shuffle(int*, int*);

int main(void){
    srand(time(0));
    int** array;
    array = (int**) malloc(N * sizeof(int*));

    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        array[i] = (int*) malloc(M * sizeof(int));
        for(int j = 0; j < M; j++){
            array[i][j] = rand() % 100000;
            printf("%5d ", array[i][j]);
        }
        printf("\n");
    }

    int k = 1;
    while(k > 0) {
        k = 0;
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < M; j++){
                if(array[i][j] < array[i - 1][j]){
                    k++;
                    shuffle(&array[i - 1][j], &array[i][j]);
                }
            }
        }
    }

    printf("Массив после сортировки:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%5d ", array[i][j]);
        }
        free(array[i]);
        printf("\n");
    }

    free(array);
    
    return 0;
}

void shuffle(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}