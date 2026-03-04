#include <stdio.h>
/* copy input to output; 2nd version */
main()
{
    int c;
    int prev_c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && prev_c == ' ')
            continue;
        putchar(c);
        prev_c = c;
    }
}