#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> 

#define N 15
#define A -100
#define B 100

int maximum(int*);
int accord_to_max(int*);
int negative_sum(int*);
int min_positive(int*);

int main(void){
    srand(time(0));

    int* array;

    array = (int*) malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        array[i] = A + rand() % (B - A + 1);
        printf("%d ", array[i]);
    }

    printf("\nКол-во элементов, оканчивающиеся на ту же цифру, что и максимум: %d", accord_to_max(array));
    printf("\nСумма отрицательных чисел: %d", negative_sum(array));
    printf("\nМинимальное позитивное: %d\n", min_positive(array));

    free(array);

    return 0;
}

int maximum(int* array){
    int max = INT_MIN;

    for(int i = 0; i < N; i++){
        if(array[i] > max)
            max = array[i];
    }

    return max;
}

int min_positive(int* array){
    int min = INT_MAX;

    for(int i = 0; i < N; i++){
        if(min > array[i] && array[i] > 0)
            min = array[i];
    }

    return min;
}

int accord_to_max(int* array){
    int amount = 0, max = maximum(array);

    for(int i = 0; i < N; i++){
        if(abs(array[i]) % 10 == abs(max) % 10)
            amount++;
    }

    return amount;
}

int negative_sum(int* array){
    int sum = 0;

    for(int i = 0; i < N; i++){
        if(abs(array[i]) != array[i])
            sum += array[i];
    }

    return sum;
}