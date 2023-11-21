#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char strokes[3][250];
    char new_strokes[3][750];
    char absurd[750];
    int c = 0;
    for(int i = 0; i < 3; i++){
        if(!scanf("%s", strokes[i])){
            exit(1);
        }
        for(int j = 0; j < strlen(strokes[i]); j++){
            absurd[c] = strokes[i][j];
            c++;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < c; j++){
            new_strokes[i][j] = absurd[j];
        }
    }
    printf("%s %s %s\n", strokes[0], strokes[1], strokes[2]);
    printf("%s %s %s\n", new_strokes[0], new_strokes[1], new_strokes[2]);
    return 0;
}
