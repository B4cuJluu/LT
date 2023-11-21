#include <stdio.h>
#include <math.h>

int main(void){

    double a_and_b[2][11];
    const double Pi = 3.14;
    double x, L, res = 0;
    char letters[] = {'a', 'b'};

    printf("Введите x: ");
    if(!scanf("%lf", &x) || x == 0){
        printf("Ошибка! Неверный ввод."); 
        return -1;
    }

    printf("Введите L: ");
    if(!scanf("%lf", &L) || L == 0){
        printf("Ошибка! Неверный ввод."); 
        return -1;
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j <= 10; j++){

            printf("Введите число для добавления в массив %c (%d): ", letters[i], j);
            if(!scanf("%lf", &a_and_b[i][j])){
                printf("Ошибка! Неверный ввод.");
                return -1;
            }
        }
    }

    res += a_and_b[0][0] / x;

    for (int n = 1; n < 11; n++){

        res += a_and_b[0][n] * cos((n * Pi * x) / L);
        res += a_and_b[1][n] * sin((n * Pi * x) / L);

    }

    printf("Ответ: %lf\n", res);

    return 0;
}