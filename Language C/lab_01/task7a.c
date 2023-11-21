#include <stdio.h>
#include <math.h> // cos и sin
#include <stdbool.h> // булевой тип
#include <string.h> // длина строки strlen

// Вычисление интеграла
double integration (double*, double*, const int, const char, char*);

// Преобразование строки в выражение
double f_read(double, char*);


int main(void){

    double L, x, res = 0; 
    int index = -1; 
    char *f_x; 

    printf("Введите положительное число L (промежуток): ");
    if(!scanf("%lf", &L) || L == 0)
        exit(1);

    printf("Введите x: ");
    if(!scanf("%lf", &x))
        exit(1);

    printf("Введите f(x) (слитно, без пробелов, только целые числа): ");    
    scanf("%s", f_x);

    res = integration(&L, &L, 0, 'a', f_x) * (1/L);

    for(int i = 1; i <= 10; i++){
        res += integration(&L, &L, i, 'a', f_x) * (1/L);
        res += integration(&L, &L, i, 'b', f_x) * (1/L);
    }

    printf("Ответ: %lf\n", res);
    return 0;
    
}


double integration (double *a, double *b, const int n, char key_letter, char *f_x){
    double x, y;

    const double Pi = 3.14;

    // чем меньше rect_width (ширина прямоугольника), тем больше точность результата интегрирования
    double rect_width = 0.01, area = 0;

    const double lower_limit = *a, upper_limit = *b;

    for (x = lower_limit * (-1); x <= upper_limit; x += rect_width){
        if(key_letter == 'a')
            y = f_read(x, f_x) * cos((Pi * n * x)/upper_limit);
        else{
            y = f_read(x, f_x) * sin((Pi * n * x)/upper_limit);
        }
        
        area += y * rect_width;

    }

    return area;
}

double f_read(double x, char *f_x){
    double f_res;
    if(f_x[0] == 'x')
        f_res = x;
    else{
        f_res = (int) f_x[0] - 48;
    }

    for(int i = 1; i < strlen(f_x); i+=2){
        double l_statement;
        if(f_x[i+1] == 'x')
            l_statement = x;
        else{
            l_statement = (int) f_x[0] - 48;
        }
        if(f_x[i] == '+')
            f_res += l_statement;
        else{
            f_res -= l_statement; 
        }
    }

    return f_res;
}