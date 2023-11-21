#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 8

int main(void){
    srand(time(0));
    int** array;
    array = (int**)malloc(N * sizeof(int*));

    for(int i = 0; i < N; i++){
        array[i] = (int*)malloc(M * sizeof(int));
        for(int j = 0; j < M; j++){
            array[i][j] = rand() % 1000;
        }
    }
    
    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%-4d ", array[i][j]);
        }
        printf("\n");
    }

    int* zero_array;
    zero_array = (int*)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < M; j++){
            if(!(array[i][j] % 10))
                count++;
        }
        zero_array[i] = count;
    }

    int* min_array;
    min_array = (int*)malloc(N * sizeof(int));

    for(int j = 0; j < M; j++){
        min_array[j] = array[0][j];
        for(int i = 0; i < N; i++){
            if(min_array[j] > array[i][j] && (abs(array[i][j]) % 2))
                min_array[j] = array[i][j];
        }
    }

    printf("\nПолучившийся массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%-4d ", array[i][j]);
        }
        free(array[i]);
        printf("%-4d\n", zero_array[i]);
    }

    free(array);
    free(zero_array);

    printf("\n");
    for(int i = 0; i < M; i++){
        printf("%-4d ", min_array[i]);
    }
    
    free(min_array);
    printf("\n");
    return 0;
}