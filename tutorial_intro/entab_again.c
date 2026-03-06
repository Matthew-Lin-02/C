#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8
/* maximum input line length */
int kgetline(char line[], int maxline);
int calculate_spaces_to_tabstop(int offset, int tab_size);
/* print the longest input line */
int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = kgetline(line, MAXLINE)) > 0) {

        int i = 0;
        int column = 0;
        int spaces = 0;
        while(i < len){    
            if(line[i] == ' '){
                
                for(int j = i; j < len && line[j] == ' '; j++){
                    ++spaces;
                }

                while(spaces > 0){
                    int spaces_to_tabstop = calculate_spaces_to_tabstop(column, TABSTOP);
                    if(spaces >= spaces_to_tabstop){
                        line[i] = '\t';

                        for(int k = i + 1; k < len - (spaces_to_tabstop - 1); k++){ // I missed the brackets here which fails (operator precedence)
                            line[k] = line[k + spaces_to_tabstop - 1];
                        }

                        column += spaces_to_tabstop;
                        spaces -= spaces_to_tabstop;
                        i++;
                        len -= spaces_to_tabstop - 1;
                    }else{
                        --spaces;
                        ++column;
                        ++i;
                    }
                }


            }else{
                if(line[i] == '\t'){
                    column += calculate_spaces_to_tabstop(column, TABSTOP);
                }
                ++i;
                ++column;
            }
        }
        line[len] = '\0';

        printf("%s", line);

    }
    return 0;
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