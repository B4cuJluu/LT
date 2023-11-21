#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10
#define M 8

int main(void){
    srand(time(0));
    int array[N][M];
    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            array[i][j] = rand() % 2 ? rand() % 1000 : (rand() % 1000) * (-1);
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }

    int max_array[N];
    long int sum;
    printf("Массив максимумов строк:\n");
    for(int i = 0; i < N; i++){
        int max = INT_MIN;
        for(int j = 0; j < M; j++){
            if(max < array[i][j] && !(abs(array[i][j]) % 3))
                max = array[i][j];
        }
        max_array[i] = max;
        printf("%d ", max_array[i]);
    }
    
    for(int i = 0; i < N; i++){
        sum += max_array[i];
    }
    printf("\nСумма: %ld\n", sum);

    return 0;
}
