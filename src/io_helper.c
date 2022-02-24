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
            fseek(stdin, 0, SEEK_END);
            *mode = -1;
            break;
        }
    }
    return ret;
}

int scan_id(int *id, char *name) {
    printf("\nEnter %s, CTRL+D to go back:\n", name);
    int a = 0;
    while (!a) {
        printf(PROMPT);
        a = scan_int(id);
        if (a == EOF)
            return EOF;
        else if (a)
            return a;
        printf("\n");
    }
    return 0;
}

int scan_date(char buf[], int size, char* welcome) {
    if (scan_char(buf, size, welcome) == EOF)
        return EOF;
    return 0;
}

int scan_time(char buf[], int size, char* welcome) {
    if (scan_char(buf, size, welcome) == EOF)
        return EOF;
    return 0;
}
