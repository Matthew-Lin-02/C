
#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8
/* maximum input line length */
int kgetline(char line[], int maxline);
int calculate_number_of_spaces(int offset, int tab_size);
/* print the longest input line */
main()
{
    int len;
    /* current line length */
    int max;
    /* maximum length seen so far */
    char line[MAXLINE];
    /* current input line */
    max = 0;
    while ((len = kgetline(line, MAXLINE)) > 0){
        for(int i = 0; i < len; i++){
            if(line[i] == '\t'){
                for(int j = 0; j < calculate_number_of_spaces(i, TABSTOP); j++){
                    putchar(' ');
                }
            }else{
                putchar(line[i]);
            }
        };
    }
    return 0;
}


int calculate_number_of_spaces(int offset, int tab_size){
    return tab_size - offset % tab_size;
}

/* getline: read a line into s, return length */
int kgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}