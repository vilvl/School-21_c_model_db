#include "main.h"


void trim(char buf[], int size) {
    for (int i = 0; i < size; ++i) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }
}

int scan_char(char buf[], int size, char* name) {
    printf("\nEnter %s or CTRL+D to go back:\n", name);
    if (fgets(buf, size, stdin) == NULL)
        return EOF;
    trim(buf, size);
    return 0;
}

int scan_int(int* mode) {
    int ret = scanf("%d", mode);
    int c;
    while ((c = scanf("%*c"))) {
        if (c == EOF) {
            *mode = -1;
            break;
        }
    }
    return ret;
}

int scan_id(int *id, char *name) {
    printf("\nEnter %s or CTRL+D to go back:\n", name);
    int a = 0;
    while (!a) {
        printf(PROMPT);
        scan_int(id);
        if (a == EOF)
            return EOF;
        else if (a)
            return a;
        printf("\n");
    }
    return 0;
}
