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
        int i = 0;
        int j = 0;
        int column = 0;
        while(i < len){
            // must iterate through regardless due to existence of tabs which would but the column in an odd position
            int last_space_index = i;
            while(i < len && column < FOLDCOLUMN){
                if(line[i] == '\t'){
                    column += calculate_spaces_to_tabstop(column, TABSTOP);   
                }else{
                    column +=1;
                }
                ++i;
            }

            int last_space = 0;
                i+=1
            int end = (len - start < FOLDCOLUMN) ? len - i : FOLDCOLUMN; //non inclusive

            start += FOLDCOLUMN;
        }
        printf("%s", line); 
    }
    return i;
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