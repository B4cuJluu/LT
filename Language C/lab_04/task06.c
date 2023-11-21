#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 5

void shuffle(int*, int*);

int main(void){
    srand(time(0));
    int* first_array;
    first_array = (int*) malloc(N * sizeof(int));
    int min = INT_MAX, min_index;

    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        first_array[i] = rand() % 10000;
        if(min > first_array[i]){
            min = first_array[i];
            min_index = i;
        }
        printf("%-4d ", first_array[i]);
    }

    int radical_amount = (N - min_index);

    for(int i = min_index + 1; i < N - radical_amount / 2; i++)
        shuffle(&first_array[N - i + min_index], &first_array[i]);
    
    printf("\nПосле перестановки:\n");
    for(int i = 0; i < N; i++){
        printf("%-4d ", first_array[i]);
    }

    free(first_array);
    int** second_array;
    second_array = (int**) malloc(N * sizeof(int*));
    
    printf("\n\nИсходный массив:\n");
    for(int i = 0; i < N; i++){
        second_array[i] = (int*) malloc(N * sizeof(int));
        for(int j = 0; j < N; j++){
            second_array[i][j] = rand() % 10000;
            printf("%-4d ", second_array[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < N; i++)
        shuffle(&second_array[i][i], &second_array[N - i - 1][i]);
    
    printf("\nПосле перестановки:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%-4d ", second_array[i][j]);
        }
        free(second_array[i]);
        printf("\n");
    }
    free(second_array);
    return 0;
}

void shuffle(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}