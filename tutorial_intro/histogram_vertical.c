#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORD_LEN 15


/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */
main()
{
    int c, len;
    len = 0;
    int nwords[MAX_WORD_LEN + 1];
    for(int i = 0; i < MAX_WORD_LEN + 1; i++) nwords[i] = 0;

    while((c = getchar()) != EOF){
        
        if(c == ' ' || c == '\t' || c == '\n'){
            len = 0; 
        } else{
            ++len;
        }


        if(len != 0){
            if(len <= MAX_WORD_LEN){
                ++nwords[len];
            }else if(len > MAX_WORD_LEN){
                ++nwords[MAX_WORD_LEN]; 
            }
        }
    }
    int max_count = 0;
    for(int i = 0; i < MAX_WORD_LEN + 1; i++){
        if(nwords[i] > max_count) max_count = nwords[i];
    }
    

    int display2d[max_count][MAX_WORD_LEN + 1]; 
    for(int i = 0; i < max_count; i++)
        for(int j = 0; j < MAX_WORD_LEN + 1; j++)
            display2d[i][j] = ' ';

    for(int i = 1; i < MAX_WORD_LEN + 1; i++){
        // printf("%d: ", i);
        for(int j = 0; j < nwords[i]; j++){
            // putchar('*');
            display2d[max_count - j - 1][i] = '*';
        }
        // putchar('\n');
    }

    for(int i = 0; i < max_count; i++){
        for(int j = 1; j <= MAX_WORD_LEN; j++)
            printf("%3c", display2d[i][j]);
        putchar('\n');
    }

    for(int i = 1; i < MAX_WORD_LEN + 1; i ++){
        printf("%3d", i);
    }
}