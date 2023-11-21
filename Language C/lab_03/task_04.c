#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *myfile;
    int n;

    myfile = fopen("input.txt", "r");

    if(!myfile){
        exit(1);
    }

    printf("Введите длину массивов: ");
    if(!scanf("%d", &n) || n <= 0){
        exit(1);
    }

    int a[n], b[n];
    for(int i = 0; i < n; i++){
        fscanf(myfile, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int j = 0; j < n; j++){
        b[j] = a[j] * a[(j + 1) % n];
        printf("%d ", b[j]);
    }
    printf("\n");
    return 0;
}