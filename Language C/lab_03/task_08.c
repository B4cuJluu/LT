#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> 
#include <float.h> 

#define N 10
#define A -100
#define B 100

int negative_strokes(double**);
double max_of_diagonal(double**);
double sum_with_zero(double**);

int main(void){
    srand(time(0));

    double** array;

    array = (double**) malloc(N * sizeof(double*));

    for(int i = 0; i < N; i++){
        array[i] = (double*) malloc(N * sizeof(double));
        for(int j = 0; j < N; j++){
            array[i][j] = A + (rand() / (double) RAND_MAX) * (B - A);
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }

    printf("\nКол-во строк, содержащие отрицательные элементы %d", negative_strokes(array));
    printf("\nМаксимальный элемент главной диагонали: %lf", max_of_diagonal(array));
    printf("\nСумма значений с нулевой целой частью: %lf\n", sum_with_zero(array));

    for(int i = 0; i < N; i++){
        free(array[i]);
    }   

    free(array);

    return 0;
}

int negative_strokes(double** array){
    int amount = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(array[i][j] < 0){
                amount++;
                break;
            }
        }
    }

    return amount;
}

double max_of_diagonal(double** array){
    double maximum = DBL_MIN;

    for(int i = 0; i < N; i++){
        if(array[i][i] > maximum)
            maximum = array[i][i];
    }
    
    return maximum;
}

double sum_with_zero(double** array){
    double sum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((int) array[i][j] == 0)
                sum += array[i][j];
        }
    }
    
    return sum;
}