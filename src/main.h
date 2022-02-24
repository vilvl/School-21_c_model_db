#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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
    SELECT,
    SELECT_ALL
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
int my_select(FILE *fp, enum db_names db_name, int init,
    int (*comp)(entrie* etalon, entrie* peek),
    entrie* etalon, entrie* ret);
// int my_select_all(FILE *, int init, entrie*, enum db_names);
int my_delete(FILE*, enum db_names, int);
int my_insert(FILE*, enum db_names, entrie*);
int my_update(FILE*, enum db_names, int, entrie *);
//////////////////////////////////////////////////////

void select_connector(FILE*, entrie*, void (*cb_printf)(entrie*));
void select_all_connector(FILE*, entrie*, void (*cb_printf)(entrie*));
void delete_connector(FILE*, entrie*);
void insert_connector(FILE*, entrie*, int (*cb_scanf)(entrie*));
void update_connector(FILE* fp, entrie* ent, int (*cb_scanf)(entrie*));
//////////////////////////////////////////////////////

void turn_off_modules();
void delete_modules();
void set_protection_for_main_module();
void set_lvl_and_cell_for_main_module();
void set_protection_by_lvl();
void run_sequence();

int comp_always_true(entrie* etalon, entrie* peek);
int comp_id_equality(entrie* etalon, entrie* peek);

void modules_process_operation(enum operations);
void levels_process_operation(enum operations);
void events_process_operation(enum operations);

entrie read_record_from_file(FILE *pfile, int index, enum db_names db_name);
void write_record_in_file(FILE *pfile, const entrie *record_to_write, int index, enum db_names db_name);
// void swap_records_in_file(FILE *pfile, int record_index1, int record_index2, enum db_names db_name);
long get_file_size_in_bytes(FILE *pfile);
long get_records_count_in_file(FILE *pfile, enum db_names db_name);

// void quickSort(FILE *fp, int low, int high);
// int compare_with_entrie(FILE* fp, int, entrie*);
// int compare_entries(entrie *a, entrie *b);

size_t size_of_entrie(enum db_names);

int scan_int(int*);
int scan_id(int*, char*, char*);
int scan_char(char buf[], int size, char* name, char*);
// int scan_date(char buf[], int size, char* welcome);
// int scan_time(char buf[], int size, char* welcome);
// int ret_end(int code, FILE* file );
// void print_file_info(FILE* fp, enum db_names);
// void print_file(FILE* fp, int entr_count);
char* get_oper_name(enum operations oper);
char* get_db_name(enum db_names oper);
void get_cur_date_time(char date[], char time[]);

#endif  // SRC_MAIN_H_
