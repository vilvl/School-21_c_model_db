#include "main.h"

void get_cur_date_time(char date_buf[], char time_buf[]) {
    time_t timer = time(NULL);
    struct tm* timeinfo = localtime(&timer);
    sprintf(date_buf, "%02d.%02d.%04d",
        timeinfo->tm_mday,
        timeinfo->tm_mon,
        timeinfo->tm_year);
    sprintf(time_buf, "%02d.%02d.%02d",
        timeinfo->tm_hour,
        timeinfo->tm_min,
        timeinfo->tm_sec);
}

char* get_oper_name(enum operations oper) {
    switch (oper) {
        case INSERT: return "INSERT";
        case DELETE: return "DELETE";
        case UPDATE: return "UPDATE";
        case SELECT: return "SELECT";
        case SELECT_ALL: return "SELECT ALL";
    }
    return "";
}

char* get_db_name(enum db_names oper) {
    switch (oper) {
        case MODULES: return "MODULES";
        case LEVELS: return "LEVELS";
        case EVENTS: return "STATUS EVENTS";
    }
    return "";
}

int scan_char(char buf[], int size, char* name, char* welcome) {
    printf("\n");
    if (welcome)
        printf("%s: ", welcome);
    printf("Enter %s or CTRL+D to go back:\n", name);
    printf(PROMPT);
    for (int i = 0; i < size; i++) {
        if (scanf("%c", &buf[i]) == EOF)
            return EOF;
        if (buf[i] == '\n') {
            buf[i] = '\0';
            return 0;
        }
    }
    return 0;
}

int scan_int(int* mode) {
    int ret = scanf("%d", mode);
    fseek(stdin, 0, SEEK_END);
    return ret;
}

int scan_id(int *id, char *name, char *welcome) {
    printf("\n");
    if (welcome)
        printf("%s: ", welcome);
    printf("Enter %s, CTRL+D to go back:\n", name);
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
