#include <stdio.h>

int main(void){
    double res = 0;
    for (double x = -12.5; x <= -6.8; x += 9.5){
        double y = -8 * x * x * x + 4 * x - 3 * x * x + 4;
        printf("%lf %lf\n", x, y);
        res += y * y;
    }
    printf("%lf\n", res);
}
