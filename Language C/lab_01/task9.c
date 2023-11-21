#include <stdio.h>

int length(int);

int main(void){
    int number;
    
    printf("Введите шестизначное натуральное число: ");
    if(!scanf("%d", &number) || length(number) != 6)
        exit(1);
    printf("%d %d\n", number / 1000, number % 1000);
    return 0;
}

int length(int n) {
    int l = 0;
    do {
        l++;
        n /= 10;
    } while(n);
    return l;
}
