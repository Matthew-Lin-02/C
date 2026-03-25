#include <stdio.h>

#define OUT 0
#define BLOCK_COMMENT 1
#define LINE_COMMENT 2 
#define STRING 3
#define CHAR 4

#define IS_OPENING(c) ((c) == '{' || (c) == '[' || (c) == '(')
#define IS_CLOSING(c) ((c) == '}' || (c) == ']' || (c) == ')')
#define STACK_MAX_SIZE 1000
int do_match(char a, char b);

int main(void)
{
    int c;
    int line = 1;
    int stack_len = 0;
    char stack[STACK_MAX_SIZE];

    int state = OUT;
    char last_char;
    while ((c = getchar()) != EOF && stack_len < STACK_MAX_SIZE) {
        //Check brackets first
            //Read Open brackets into stack 
            //Attempt pop brakcets off of stack print error if something wrong
        // Don't forget about quotes, both single and double, escape sequences, and comments
            // track the current state of whether you're in a comment a double quote or quote
            // think rudimentary to being with
            // first lets track if we're in a comment

        if(state == OUT){
            if(c == '\n'){
                ++line;
            }

            if(stack_len == 0 && IS_CLOSING(c)){
                printf("error: unexpected '%c' at line %d\n", c, line);
                break;
            }

            if(IS_OPENING(c)){
                stack[stack_len++] = c;
            }else if(IS_CLOSING(c)){
                if(!do_match(stack[--stack_len], c)){
                    printf("error: unexpected '%c' at line %d\n", c, line);
                    break;
                }
            }
        }

        if(state == BLOCK_COMMENT){
            if(last_char == '*' && c == '/'){
                state = OUT;
            }
        }
        else if(state == LINE_COMMENT){
            if(c == '\n'){
                state = OUT;
            }
        }else if(state == STRING){
            if (c == '\\') {
                getchar(); // skip escaped char
            }
            if(c == '"'){
                state = OUT;
            }
        }else if(state == CHAR){
            if(c == '\''){
                state = OUT;
            }    
        }else if(state == OUT){
            if(c == '"'){
                state = STRING;
            }else if(c == '\''){
                state = CHAR;
            }else if(last_char == '/' && c == '*'){
                state = BLOCK_COMMENT;
            }else if(last_char == '/' && c == '/'){
                state = LINE_COMMENT;
            }
        }

        last_char = c;
    }

    // Im lazy so im doing it like this but technically you should check somehow else 
    // with more lexical complexity for different cases
    if(state != OUT){
        printf("error: unlcosed string or block comment at EOF\n");
    }

   
}
// you can do static inline int for optimisation purposes
int do_match(char a, char b) {
    return (a == '{' && b == '}') ||
           (a == '[' && b == ']') ||
           (a == '(' && b == ')');
}