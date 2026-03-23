#include <stdio.h>
#define MAXLINE 1000
#define FOLDCOLUMN 3
#define TABSTOP 8
/* maximum input line lengths */
int kgetline(char line[], int maxline);
int calculate_spaces_to_tabstop(int offset, int tab_size);
/* print the longest input line */
int main(void)
{
    int len;
    char line[MAXLINE];
    int i, column,spaceholder;

    while ((len = kgetline(line, MAXLINE)) > 0) {
        if(len < FOLDCOLUMN){

        }else{
            spaceholder = -1;
            i = 0;
            column = 0;
            while(i < len){
                if(line[i] == ' ' || line[i] == '\n'){
                    spaceholder = i;                    
                }

                if(column == FOLDCOLUMN){
                    if(spaceholder == -1){

                        for(int j = len+1; j > i; j--){
                            line[j] = line[j-1];
                        }
                        len++;
                        line[i] = '\n';
                        
                        // haven't learnt realloc malloc would need to shift the array to the right and realloc with extra char space. 
                    }else{
                        line[spaceholder] = '\n';
                        i = spaceholder;
                    }
                    column = -1;
                    spaceholder = -1;
                }

                i++;
                column++;
            } 

        }
        printf("%s", line);        
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