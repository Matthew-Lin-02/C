#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */
int kgetline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], int len);
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
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[], int len){
 
    int end = len - 1;
    if(s[end] == '\n'){
        --end;
    }

    char c;
    for(int i = 0; i < end/2; i++){
        char c = s[end - i];  
        s[end - i] = s[i];
        s[i] = c;
    }

    // This is a little more clear
    // int start = 0
    // while (start < end) {
    //     char temp = s[start];
    //     s[start] = s[end];
    //     s[end] = temp;

    //     start++;
    //     end--;
    // }
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