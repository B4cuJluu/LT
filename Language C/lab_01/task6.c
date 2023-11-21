#include <stdio.h>

int main()
{
    int a, b;
    
    if (!scanf("%d %d", &a, &b)){
        printf("Ошибка! Неверный ввод.");
        return -1;
    }
    if(a > b){
        printf("a > b");
    }
    else if(a < b){
        printf("a < b");
    }
    else{
        printf("a == b");
    }
    return 0;
}
