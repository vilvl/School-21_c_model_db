#include "main.h"

void select_connector(FILE* fp, entrie* ent, void (*cb_print_ent)(entrie*)) {
    int id;
    if (scan_id(&id, "id") == EOF)
        return;
    switch (select(fp, id, ent, ent->db_name)) {
        case 1: cb_print_ent(ent); break;
        default: printf("n/a\n");
    }

}

void delete_connector(FILE* fp, entrie* ent) {
    int id;
    if (scan_id(&id, "id") == EOF)
        return;
    switch (delete(fp, id, ent->db_name)) {
        case 1: printf("success\n"); break;
        default: printf("n/a\n");
    }
}

void insert_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*)) {
    if (cb_scanf_ent(ent) == EOF)
        return;
    switch (insert(fp, ent, ent->db_name)) {
        case 1: printf("success\n"); break;
        default: printf("n/a\n");
    }
}

void update_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*)) {
    int id;
    if (scan_id(&id, "id") == EOF)
        return;
    if (cb_scanf_ent(ent) == EOF)
        return;
    switch (update(fp, id, ent, ent->db_name)) {
        case 1: cb_print_ent(ent); break;
        default: printf("n/a\n");
    }
}
