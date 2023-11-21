#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define A -100
#define B 100

int main(void){
    srand(time(0));
    FILE *myfile;

    myfile = fopen("output.txt", "w");

    int counter = 0, sum = 0;
    int *a, *b;
    a = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        a[i] = A + rand() % (B - A + 1);
        if(a[i] > 0){
            sum += a[i];
        }
        fprintf(myfile, "%d ", a[i]);
    }

    b = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        if(abs(a[i]) % 10 == sum % 10){
            b[counter++] = a[i];
        }
    }

    free(a);
    fprintf(myfile, "\nКол-во элементов, подходящие под условия: %d\n", counter);

    for (int j = 0; j < counter; j++){
        fprintf(myfile, "%d ", b[j]);
    }

    free(b);
    fclose(myfile);

    return 0;
}