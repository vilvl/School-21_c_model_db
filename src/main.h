#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum operations {
    INSERT,
    DELETE,
    UPDATE,
    SELECT
};

enum db_names {
    LEVELS = 1,
    MODULES = 2,
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
        struct levels_entrie level;
        struct modules_entrie modules;
        struct events_entrie events;
    } rec;
} entrie;

//////////////////////////////////////////////////////
// 1 for success, -1 for error, 0 for no match
int select(FILE *db, int id, entrie* ent, enum db_names db_name);
int delete(FILE *db, int id, enum db_names db_name);
int insert(FILE *db, entrie *entity, enum db_names db_name);
int update(FILE *db, int id, entrie *entity, enum db_names db_name);
//////////////////////////////////////////////////////

entrie read_record_from_file(FILE *pfile, int index, enum db_names db_name);
void write_record_in_file(FILE *pfile, const entrie *record_to_write, int index, enum db_names db_name);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2, enum db_names db_name);
long get_file_size_in_bytes(FILE *pfile);
long get_records_count_in_file(FILE *pfile, enum db_names db_name);

void quickSort(FILE *fp, int low, int high);
int compare_with_entrie(FILE* fp, int, entrie*);
int compare_entries(entrie *a, entrie *b);

int scan_int(int* mode);

int ret_end(int code, FILE* file );
void print_file_info(FILE* fp, enum db_names);
void print_file(FILE* fp, int entr_count);

#endif  // SRC_MAIN_H_
