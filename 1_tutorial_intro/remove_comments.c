#include <stdio.h>
#define MAXLINE 1000
#define FOLDCOLUMN 10
#define TABSTOP 8
#define OUT 0
#define IN 1
#define INNEW 2 
#define INSTRING 3
#define INCHAR 4
/* maximum input line lengths */
int kgetline(char line[], int maxline);
int calculate_spaces_to_tabstop(int offset, int tab_size);
/* print the longest input line */

int main(void)
{
    int len;
    char line[MAXLINE];


    while ((len = kgetline(line, MAXLINE)) > 0) {
        int state = OUT;
        char last_char = ' ';
        for(int k = 0; k < len; k++){
            if(state == IN){
                if(line[k] == '*' && line[k+1] == '/'){
                    state = OUT;
                    k+=2;
                }
            else if(state == INNEW){
                
            }
            }else if(state == INSTRING){
                if(line[k] == '"'){
                    state = OUT;
                }
            }else if(state == INCHAR){
                if(line[k] == '\''){
                    state = OUT;
                }    
            }else if(state == OUT){
                if(line[k] == '"'){
                    state = INSTRING;
                }else if(line[k] == '\''){
                    state = INCHAR;
                }else if(line[k] == '/' && line[k+1] == '*'){
                    state = IN;
                    k += 2;
                }else if(line[k] == '/' && line[k+1] == '/'){
                    state = INNEW;
                    k += 2;
                }
            }
            
            if(k == len - 1 && line[k] == '\n'){
                putchar(line[k]);
            }else if(state != IN && state != INNEW){
                putchar(line[k]);
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