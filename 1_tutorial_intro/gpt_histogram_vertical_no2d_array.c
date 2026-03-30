#include <stdio.h>

#define MAX_WORD_LEN 15

int main(void)
{
    int c, len = 0;
    int nwords[MAX_WORD_LEN + 1];

    // initialize counts
    for (int i = 0; i <= MAX_WORD_LEN; i++)
        nwords[i] = 0;

    // count word lengths
    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\t' || c == '\n') {
            if (len > 0) {
                if (len <= MAX_WORD_LEN)
                    ++nwords[len];
                else
                    ++nwords[MAX_WORD_LEN];
                len = 0;
            }
        } else {
            ++len;
        }
    }

    // handle last word if file doesn't end with whitespace
    if (len > 0) {
        if (len <= MAX_WORD_LEN)
            ++nwords[len];
        else
            ++nwords[MAX_WORD_LEN];
    }

    // find max height
    int max_count = 0;
    for (int i = 1; i <= MAX_WORD_LEN; i++)
        if (nwords[i] > max_count)
            max_count = nwords[i];

    // print vertical histogram
    for (int level = max_count; level > 0; level--) {
        for (int i = 1; i <= MAX_WORD_LEN; i++) {
            if (nwords[i] >= level)
                printf("%3c", '*');
            else
                printf("%3c", ' ');
        }
        putchar('\n');
    }

    // print axis labels
    for (int i = 1; i <= MAX_WORD_LEN; i++)
        printf("%3d", i);

    putchar('\n');

    return 0;
}