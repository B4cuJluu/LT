#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(0));
    for(int j = 1; j < 3; j++){
        for(int i = 1; i < 9; i++){
            if(i * j == 16){
                break;
            }
            int a = 10 + rand() % 90;
            while(a%10 + a/10 > 10){
                a = 10 + rand() % 90;
            }
            printf("%d ", a);
        }
        printf("\n");
    }
    return 0;
}
