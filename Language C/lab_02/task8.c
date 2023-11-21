#include <stdio.h>

double function(double);
double summa(double, double, double);

int main(void){
    double value[3];
    int i = 0;
    for (double x = -12.5; x <= -6.8; x += 9.5){
        double y = function(x);
        printf("%lf %lf\n", x, y);
        value[i] = y;
        i++;
    }
    double result = summa(value[0], value[1], value[2]);
    printf("%lf\n", result);
}

double function(double x){
    double y = -8 * x * x * x + 4 * x - 3 * x * x + 4;
    return y;
}

double summa(double a, double b, double c){
    return a*a + b*b + c*c;
}