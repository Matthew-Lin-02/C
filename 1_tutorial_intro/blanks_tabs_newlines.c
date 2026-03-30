#include <stdio.h>
/* count lines in input */
main() 
{
    int c, nl, tabs, blanks;
    nl = tabs = blanks = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
    }
    
    printf(
        "newlines: %d \n"
        "tabs: %d \n"
        "blanks: %d \n",
        nl, tabs, blanks
    );
}