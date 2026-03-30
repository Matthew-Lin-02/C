// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
/*
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int kgetline(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = kgetline(line, MAXLINE)) > 0){
        printf("%d", len);
    }
    return 0;
}

int kgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1; ++i){
        if((c = getchar()) == EOF){
            break;
        }else if(c == '\n'){
            break;
        }

        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
