#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(0));
    int n;
    printf("Введите длину массивов: ");
    if(!scanf("%d", &n) || n <= 0){
        exit(1);
    }
    int a[n];
    int A, B;
    printf("Введите диапазон для целочисленного массива: ");
    if(!scanf("%d %d", &A, &B) || A > B){
        exit(1);
    }
    double b[n];
    double C, D;
    printf("Введите диапазон для вещественного массива: ");
    if(!scanf("%lf %lf", &C, &D) || C > D){
        exit(1);
    }
    for (int i = 0; i < n; i++){
        a[i] = A + rand() % (B - A + 1);
        b[i] = C + (rand() / (double) RAND_MAX) * (D - C);
        printf("a[%d] = %d; b[%d] = %f\n", i, a[i], i, b[i]);
    }
    return 0;
}