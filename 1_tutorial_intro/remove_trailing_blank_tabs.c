#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */
int kgetline(char line[], int maxline);
int trimline(char s[], int len);
void copy(char to[], char from[]);
/* print the longest input line */
main()
{
    int len;
    /* current line length */
    int max;
    /* maximum length seen so far */
    char line[MAXLINE];
    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = kgetline(line, MAXLINE)) > 0){
        trimline(line, len);
        printf("%s", line);
    }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

int trimline(char s[], int len)
{
    int c;
    // printf("%d", len);
    int start = 0;
    int end = len - 1;
    while(start < len && (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')){
        ++start;
    }

    while(end >= start && (s[end] == '\n' || s[end] == '\t' || s[end] == ' ')){
        --end;
    }

    int new_len = end - start + 1;


    for(int i = 0; i < new_len; i++){
        s[i] = s[start + i];
    }
    s[new_len] = '\0';
    return new_len;

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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}