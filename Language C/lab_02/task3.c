#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int x;

    while(1){
        printf("Введите целое отрицательное число: ");
        scanf("%d", &x);
        if(x < 0){
            break;
        }        
    }

    do {
        x += 7;
        printf("%d + 7 = %d\n", x - 7, x);
    } while(x < 0);
    return 0;
}
