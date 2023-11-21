#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void shuffle(int*, int*);

int main(void){
    srand(time(0));
    int* array;
    array = (int*)malloc(N * sizeof(int));

    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        array[i] = rand() % 10000;
        printf("%d ", array[i]);
    }

    for(int i = 1; i < N; i++){
        if(array[i - 1] < array[i]){
            shuffle(&array[i - 1], &array[i]);
            i++;
        }
    }

    printf("\nМассив после изменений:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }

    free(array);
    
    return 0;
}

void shuffle(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}