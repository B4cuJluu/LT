#include <stdio.h>

int main(void){
    int code;
    printf("Введите число: ");
    if(!scanf("%d", &code)){
        printf("Ошибка! Неверный ввод.");
        return -1;
    }
    printf("%d\n", code);
    code++;
    printf("%d\n", code);
    code -= 7;
    printf("%d\n", code);
    code *= -1;
    printf("%d\n", code);
    code += 2;
    printf("%d\n", code);
    code /= 4;
    printf("%d\n", code);
    return 0;
}
