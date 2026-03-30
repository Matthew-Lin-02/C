
#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8
/* maximum input line length */
int kgetline(char line[], int maxline);
int spaces_to_tabstop(int offset, int tab_size);
/* print the longest input line */
int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = kgetline(line, MAXLINE)) > 0) {

        int i = 0;
        int column = 0;

        while (i < len) {

            if (line[i] == ' ') {

                int j = i;

                while(line[j] == ' '){
                    j++;
                }

                int spaces = j - i;

                while(spaces > 0){
                    int to_tabstop = spaces_to_tabstop(column, TABSTOP); 
                    if(spaces >= to_tabstop){
                        putchar('\t');
                        spaces -= to_tabstop;
                        column += to_tabstop;
                    }else{
                        putchar(' ');
                        --spaces;
                        ++column;
                    }
                }
                i = j;
            }
            else {
                putchar(line[i]);

                if(line[i] == '\t'){
                    column += spaces_to_tabstop(column, TABSTOP);
                }else{
                    column ++;
                }
                i++;
 
            }
        }
    }

    return 0;
}


int spaces_to_tabstop(int offset, int tab_size){
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