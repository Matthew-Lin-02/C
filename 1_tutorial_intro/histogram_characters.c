#include <stdio.h>

#define UCHAR_MAX 255


main(){
    // accomodate for 0 
    int char_count[UCHAR_MAX + 1];
    int c;

    for(int i = 0; i < UCHAR_MAX + 1; i++)
        char_count[i] = 0;
        
    while((c = getchar()) != EOF){
        ++char_count[c];
    }

    int max_char_count = 0;
    for(int i = 0; i < UCHAR_MAX + 1; i++){
        if(char_count[i] > max_char_count){
            max_char_count = char_count[i];
        }
    }
    
    for(int level = max_char_count; level > 0; level--){
        for(int i = 1; i < UCHAR_MAX + 1; i++){
            if(char_count[i] == 0){
                continue;
            }else if(char_count[i] >= level){
                printf("%2c", '*');
            }else{
                printf("%2c", ' ');
            }

        }
        putchar('\n');
    }

    for(int i = 1; i < UCHAR_MAX + 1; i++){
        char label = (i >= 32 && i <= 126) ? i : ' ';
       
        if(char_count[i] != 0)
            printf("%2c", label);
    }



}