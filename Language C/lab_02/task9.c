#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char names[10][20];
    for(int i = 0; i < 10; i++){
        if(!scanf("%s", names[i])){
            exit(1);
        }
    } 
    for(int i = 0; i < 10; i++){
        char vowels[] = {'a', 'e', 'i', 'y', 'o', 'u'};
        char last_char = names[i][strlen(names[i]) - 1];
        for(int j = 0; j < 6; j++){
            if(last_char == vowels[j]){
                printf("%s\n", names[i]);
                break;
            }
        }
    }
    return 0;
}
