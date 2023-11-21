#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void array_pushing_rand(int*, int);
void sorting(int*, int, int);
void array_pushing(int*, int*, int);
void array_print(int*, int, int);
void shuffle(int*, int*);

int main(void){
    srand(time(0));
    int* first_array, *second_array;

    first_array = (int*) malloc(N * sizeof(int));
    second_array = (int*) malloc(N * sizeof(int));

    array_pushing_rand(first_array, 0);
    array_pushing_rand(second_array, 0);

    printf("Исходные массивы:\n");
    array_print(first_array, N, N);
    array_print(second_array, N, N);

    sorting(first_array, 0, N);
    sorting(second_array, 1, N);

    printf("Отсортированные массивы:\n");
    array_print(first_array, N, N);
    array_print(second_array, N, N);

    int* result, *add_array;

    result = (int*) malloc(N * 2 * sizeof(int));
    add_array = (int*) malloc((N / 2) * sizeof(int));

    for(int i = 0; i < 4; i++){
        int half = (int) i>=2, index = 0;
        if(i % 2 == 0){
            array_pushing(add_array, first_array, half);
        }
        else{
            array_pushing(add_array, second_array, half);
        }
        for(int j = (N/2) * i; j < (N/2) * (i+1); j++){
            result[j] = add_array[index];
            index++;
        }

    }
    
    free(first_array);
    free(second_array);
    free(add_array);

    printf("*Франкенштейн*:\n");
    array_print(result, N*2, N*2);

    sorting(result, 0, N*2);

    printf("Результат:\n");
    array_print(result, N*2, N*2);

    free(result);
    
    return 0;
}
void array_pushing_rand(int* array, int i){
    array[i] = rand() % 1000;
    if(i != N - 1)
        array_pushing_rand(array, ++i);
}

void array_print(int* array, int ind, int size){
    printf("%d ", array[size - ind]);
    if(ind - 1)
        array_print(array, ind - 1, size);
    else
        printf("\n");
}

void sorting(int* array, int key, int size){
    int k = 1;
    while (k > 0){
        k = 0;
        for(int i = 1; i < size; i++){
            if((array[i] > array[i - 1]) && (key)){
                shuffle(&array[i], &array[i - 1]);
                k++;
            }
            if((array[i] < array[i - 1]) && !(key)){
                shuffle(&array[i], &array[i - 1]);
                k++;
            }
        }
    }
}

void array_pushing(int* array, int* source, int half){
    for(int m = (N/2) * half; m < N/2 + (N/2) * half; m++){
        array[m - (N/2) * half] = source[m];
    }
}

void shuffle(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
