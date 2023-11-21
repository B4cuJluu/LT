#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 8

int main(void){
    srand(time(0));
    int first_array[N];
    int second_array[N][M];
    int amount = 0, ind = 0;

    for(int i = 0; i < N; i++){
        first_array[i] = rand() % 2 ? rand() % 1000 : (rand() % 1000) * (-1);
        for(int j = 0; j < M; j++){
            second_array[i][j] = rand() % 2 ? rand() % 1000 : (rand() % 1000) * (-1);
        }
    }

    int* first_new_array;
    for(int i = 0; i < N; i++){
        int value = first_array[i];
        if(abs(value) % 10 == 2){
            amount++;
        }
    }

    first_new_array = (int*)malloc(amount * sizeof(int));

    for(int i = 0; i < N; i++){
        int value = first_array[i];
        if(abs(value) % 10 == 2){
            first_new_array[ind] = value;
            ind++;
        }
    }

    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", first_array[i]);
    }

    printf("\nПолучившийся массив:\n");
    for(int i = 0; i < amount; i++){
        printf("%d ", first_new_array[i]);
    }
    amount = 0, ind = 0;

    printf("\n");
    free(first_new_array);

    int* second_new_array;

    for(int i = 1; i < N; i += 2){
        for(int j = 0; j < M; j++){
            int value = second_array[i][j];
            if(value < 0)
                amount++;
        }
    }
    
    second_new_array = (int*)malloc(amount * sizeof(int));

    for(int i = 1; i < N; i += 2){
        for(int j = 0; j < M; j++){
            int value = second_array[i][j];
            if(value < 0){
                second_new_array[ind] = value;
                ind++;
            }
        }
    }
    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%-5d ", second_array[i][j]);
        }
        printf("\n");
    }

    printf("Получившийся массив:\n");
    for(int i = 0; i < amount; i++){
        printf("%d ", second_new_array[i]);
    }

    printf("\n");
    free(second_new_array);

    return 0;
}