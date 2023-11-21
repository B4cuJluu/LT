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
    int A, B, counter = 0;
    printf("Введите диапазон для целочисленного массива: ");
    if(!scanf("%d %d", &A, &B) || A > B){
        exit(1);
    }
    for (int i = 0; i < n; i++){
        a[i] = A + rand() % (B - A + 1);
        printf("%d ", a[i]);
    }
    for (int j = n - 1; j >= 0; j--){
        if(abs(a[j]) % 4 == 0){
            counter++;
        }
        if(counter == 2){
            printf("\nВторое с конца массива число, кратное 4: %d\n", a[j]);
            break;
        }
    }
    if(counter != 2){
        printf("\nЧисла, кратные 4 не обнаружены.\n");
    }
    return 0;
}