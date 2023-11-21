#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomizer(int x, int y){
    return x + (rand() / (double) RAND_MAX) * (y - x);
}


int main(void){
    FILE *myfile;
    myfile = fopen("output.txt", "w");
    srand(time(0));
    int x, y;
    if(!scanf("%d %d", &x, &y) || x > y)
        exit(1);
    int a = x + rand() % (y - x + 1);
    double b = randomizer(x, y);
    double c = randomizer(x, y);
    double d = randomizer(x, y);
    fprintf(myfile, "%d %f %f %f", a, b, c, d);
    fclose(myfile);
    return 0;
}