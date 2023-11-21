#include "stdio.h"

int main(void){
    float r_1, r_2, r_3, r_4, r_5;
    int z_1, z_2, z_3;

    FILE *myfile;

    myfile = fopen("data_4.txt", "r");
    
    if(!myfile)
        perror("Ошибка!");

    if (!fscanf(myfile, "%f %f %f %f %f", &r_1, &r_2, &r_3, &r_4, &r_5))
        exit(1);

    printf("%f %f %f %f %f\n", r_1, r_2, r_3, r_4, r_5);
        
    if (!fscanf(myfile, "%d %d %d", &z_1, &z_2, &z_3))
        exit(1);

    printf("%d %d %d\n", z_1, z_2, z_3);
    return 0;
}