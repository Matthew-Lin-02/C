#include <stdio.h>
#define IN 1
#define OUT 0
#include <stdbool.h>
/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */
main()
{
    int c, state;
    state = OUT;
    bool first_word_printed = true;
    while ((c = getchar()) != EOF)
    {

        if (c == '\n'){
            putchar('\n');  
            first_word_printed = false;
            state = OUT;
        }
        
        if(!first_word_printed){
            if (c == ' ' || c == '\t'){
                if(state == IN){
                    first_word_printed = true;
                }
                state = OUT;
            }
            else if (first_word_printed == false)
            {   
                state = IN;
                putchar(c);        
            }

        }

    }
}