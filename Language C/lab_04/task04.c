#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10

int main(void){
    int array[N][N], k;
    int min = INT_MAX, max = INT_MIN;
    int min_stroke, max_row;
    printf("Исходный массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            array[i][j] = rand() % 1000;
            printf("%-3d ", array[i][j]);
        }
        printf("\n");
    }

    printf("Введите номер строки, которой вы хотите поменять местами с предпоследней: ");
    if(!(scanf("%d", &k)) || (k > 9) || (k < 0)){
        exit(1);
    }

    for(int i = 0; i < N; i++){
        int a = array[N-2][i], b = array[k][i];
        array[k][i] = a;
        array[N-2][i] = b;
    }


    printf("Массив после 1-ой перестановки:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%-3d ", array[i][j]);
            if(array[i][j] > max){
                max = array[i][j];
                max_row = j;
            }
            if(array[i][j] < min){
                min = array[i][j];
                min_stroke = i;
            }  
        }
        if(i == k || i == N - 2)
            printf("%3c", '!');
        printf("\n");
    }

    printf("\nmax: %d, min: %d\n", max, min);

    for(int i = 0; i < N; i++){
        int a = array[min_stroke][i], b = array[i][max_row];
        array[i][max_row] = a;
        array[min_stroke][i] = b;
    }
    printf("\nМассив после 2-ой перестановки:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%-3d ", array[i][j]);
        } 
        if(i == min_stroke)
            printf("%3c", '!');
        printf("\n");
        
    }
    for(int i = 0; i < N; i++){
        if(i == max_row)
            printf(" ! ");
        else{
            printf("    ");
        }
    }

    return 0;
}
