#include <stdio.h>

double integration (const double *a, const double *b){
    double x, y;
    double rect_width = 0.01, area = 0;
    const double lower_limit = *a, upper_limit = *b;

    for(x = lower_limit; x <= upper_limit; x += rect_width){

        y = x*x + 1;
        
        area += y * rect_width;
    }

    return area;
}

int main(void){
    double a = 1, b = 5;
    printf("%f\n", integration(&a, &b));
    return 0;
}