#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 7; j++){
            int a = -10 + rand() % 67;
            printf("%d ", a);
        }
        printf("\n");
    }
    for(int i = 0; i < 10; i++){
        int a = -10 + rand() % 67;
        printf("%d\n", a);
    }
    return 0;
}
