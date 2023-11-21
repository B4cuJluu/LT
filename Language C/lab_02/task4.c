#include <stdio.h>

int main()
{
    int x;
    for(int i = 0; i < 10; i++){
        printf("Введите число: ");
        scanf("%d", &x);
        int res = 1;
        while(x != 0){
            int remainder = x % 10;
            x /= 10;
            res *= remainder;
        }
        printf("%d \n", res);
    }
}
