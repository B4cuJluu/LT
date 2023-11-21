#include "stdio.h"

int main(void){
    FILE *myfile;

    int z_1, z_2;
    float r_1, r_2, r_3;

    myfile = fopen("data_5.txt", "r");
    
    if(!myfile)
        perror("Ошибка");
    
    if (!fscanf(myfile, "%d %d", &z_1, &z_2))
        exit(1);

    if (!fscanf(myfile, "%f %f %f", &r_1, &r_2, &r_3))
        exit(1);

    z_1 > z_2 ? printf("%d\n", z_1) : printf("%d\n", z_2);
    r_1 > r_2 ? r_3 > r_2 ? printf("%f\n", r_2) : printf("%f\n", r_3) : r_3 > r_1 ? printf("%f\n", r_1) : printf("%f\n", r_3); 
    return 0;
}