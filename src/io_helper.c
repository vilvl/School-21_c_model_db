#include "main.h"

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