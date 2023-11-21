#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculation(int alpha, int beta, double z){
    double y = 2 * cos(cos(0.5 * (alpha/z + beta)));
    return y;
}

int main(void){
    FILE *myfile;
    myfile = fopen("input.txt", "r");
    int a, b;
    double z;
    if(!myfile){
        exit(1);
    }
    if(!fscanf(myfile, "%d %d %lf", &a, &b, &z) || z == 0){
        exit(1);
    }
    double result = calculation(a, b, z);
    printf("%lf\n", result);
    return 0;
}
