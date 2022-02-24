#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef _DB_MODULES_PATH_
    #define _DB_MODULES_PATH_ "materials/master_modules.db"
#endif
#ifndef _DB_LEVELS_PATH_
    #define _DB_LEVELS_PATH_ "materials/master_levels.db"
#endif
#ifndef _DB_EVENTS_PATH_
    #define _DB_EVENTS_PATH_ "materials/master_status_events.db"
#endif

#define PROMPT "-> "

enum operations {
    INSERT,
    DELETE,
    UPDATE,
    SELECT
};

enum db_names {
    MODULES = 1,
    LEVELS = 2,
    EVENTS = 3
};

struct levels_entrie {
    int lvl_id;
    int cells;
    int protected;
};

struct modules_entrie {
    int mod_id;
    char name[30];
    int lvl_id;
    int cell;
    int delete_flag;
};

struct events_entrie {
    int event_id;
    int mod_id;
    int status;
    char date[11];
    char time[9];
};

typedef struct entrie {
    enum db_names db_name;
    union {
        int id;
        struct levels_entrie levels;
        struct modules_entrie modules;
        struct events_entrie events;
    } rec;
} entrie;

//////////////////////////////////////////////////////
// 1 for success, -1 for error, 0 for no match
int my_select(FILE*, int, entrie*, enum db_names);
int my_delete(FILE*, int, enum db_names);
int my_insert(FILE*, entrie*, enum db_names);
int my_update(FILE*, int, entrie *, enum db_names);
//////////////////////////////////////////////////////

void select_connector(FILE* fp, entrie* ent, void (*cb_print_ent)(entrie*));
void delete_connector(FILE* fp, entrie* ent);
void insert_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*));
void update_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*));
//////////////////////////////////////////////////////

void get_active_modeules();
void delete_module_by_id();
void set_protection_by_id();
void set_lvl_and_cell_by_id();
void set_protection_by_lvl();

void modules_process_operation(enum operations);
void levels_process_operation(enum operations);
void events_process_operation(enum operations);

entrie read_record_from_file(FILE *pfile, int index, enum db_names db_name);
void write_record_in_file(FILE *pfile, const entrie *record_to_write, int index, enum db_names db_name);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2, enum db_names db_name);
long get_file_size_in_bytes(FILE *pfile);
long get_records_count_in_file(FILE *pfile, enum db_names db_name);

// void quickSort(FILE *fp, int low, int high);
// int compare_with_entrie(FILE* fp, int, entrie*);
// int compare_entries(entrie *a, entrie *b);

int scan_int(int*);
int scan_id(int*, char*);
int scan_char(char buf[], int size, char* name);
int scan_date(char buf[], int size, char* welcome);
int scan_time(char buf[], int size, char* welcome);
// int ret_end(int code, FILE* file );
// void print_file_info(FILE* fp, enum db_names);
// void print_file(FILE* fp, int entr_count);

#endif  // SRC_MAIN_H_
