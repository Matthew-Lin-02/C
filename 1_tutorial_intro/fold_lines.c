#include <stdio.h>
#define MAXLINE 1000
#define FOLDCOLUMN 10
#define TABSTOP 8
/* maximum input line lengths */
int kgetline(char line[], int maxline);
int calculate_spaces_to_tabstop(int offset, int tab_size);
/* print the longest input line */
int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = kgetline(line, MAXLINE)) > 0) {

        int i, j;
        i = j = 0;
        while(i<len){
            int last_whitespace = -1;
            j = i;

            while(j < i + FOLDCOLUMN && j < len){
                if(line[j] == ' '){
                    last_whitespace = j;
                }
                j++;
            }

        

            int end_line = last_whitespace == -1 ? j : last_whitespace;

            if (j < i + FOLDCOLUMN){
                end_line = j;
            }
            
            for(; i < end_line; i++){
                putchar(line[i]);
            }

            putchar('\n');

            if(last_whitespace != -1){
                i++;   // skip the space we broke at
            }
        }


        
    }
}

int calculate_spaces_to_tabstop(int offset, int tab_size){
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