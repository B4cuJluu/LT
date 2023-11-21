#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(0));
    int n, i = 0;
    printf("Введите длину массива: ");
    if(!scanf("%d", &n) || n <= 0){
        exit(1);
    }
    double a[n];
    while(i < n){
        double c = (double) rand();
        if(((int) c % 4 == 0) && (c > 0)){
            a[i] = -1 * c;
            printf("%lf ", a[i]);
            i++;
        }
    }
    return 0;
}