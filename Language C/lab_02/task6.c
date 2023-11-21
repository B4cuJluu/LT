#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_str(int, int, int);
void print_stb(int, int, int);

int main(void){
	srand(time(0));
	print_str(0, 56, 15);
	print_stb(0, 56, 9);
	return 0;
}

void print_str(int a, int b, int c){
	FILE *myfile;
    myfile = fopen("output.txt", "w");
	for(int i = 0; i < c; i++){
		int number = a + rand() % (b + 1);
		fprintf(myfile, "%d ", number);
	}
}

void print_stb(int a, int b, int c){
	for(int i = 0; i < c; i++){
		int number = a + rand() % (b + 1);
		printf("%d\n", number);
	}
}	