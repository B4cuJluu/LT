#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 4
#define M 8
#define A -100
#define B 100


int main(void){
    srand(time(0));
    FILE *myfile;

    myfile = fopen("array.txt", "w");

    int** init_array;

    init_array = (int**) malloc(N * sizeof(int*));

    for(int i = 0; i < N; i++){
        init_array[i] = (int*) malloc(M * sizeof(int));
        for(int j = 0; j < M; j++){
            init_array[i][j] = A + rand() % (B - A + 1);
            fprintf(myfile, "%d ", init_array[i][j]);
        }
        fprintf(myfile, "\n");
        free(init_array[i]);
    }
    free(init_array);

    fclose(myfile);

    myfile = fopen("array.txt", "r");

    int** new_array;

    new_array = (int**) malloc(N * sizeof(int*));

    for(int i = 0; i < N; i++){
        new_array[i] = (int*) malloc(M * sizeof(int));
        for(int j = 0; j < M; j++){
            fscanf(myfile, "%d", &new_array[i][j]);
            printf("%d ", new_array[i][j]);
        }
        printf("\n");
    }

    fclose(myfile);

    int min = INT_MAX, amount = 0, sum = 0;

    for(int i = 0; i < N && i < M; i++){
        if(new_array[i][i] < min){
            min = new_array[i][i];
        }
    }

    for(int i = 0; i < N; i += 2){
        for(int j = 0; j < M; j++){
            if(new_array[i][j] < 0)
                amount++;
        }
    }

    for(int i = N - 1; i >= 0; i--){
        sum += new_array[i][N - i - 1];
    }

    for(int i = 0; i < N; i++){
        free(new_array[i]);
    }

    free(new_array);

    printf("\nМинимальный элемент главной диагонали: %d", min);
    printf("\nКол-во отрицательных элементов на четных строках: %d", amount);
    printf("\nСумма элементов побочной диагонали: %d\n", sum);
    return 0;
    
}
