#include "main.h"

int comp_id_equality(entrie* etalon, entrie* peek) {
    return (etalon->rec.id == peek->rec.id);
}

int comp_always_true(entrie*const etalon, entrie*const peek) {
    // peek = etalon;
    return (peek || etalon);
}

void select_connector(FILE* fp, entrie* ent, void (*cb_print_ent)(entrie*)) {
    if (scan_id(&ent->rec.id, "id", get_db_name(ent->db_name)) == EOF)
        return;
    if (my_select(fp, ent->db_name, 1, comp_id_equality, ent, ent) == 1) {
        cb_print_ent(ent);
        // while (my_select_all(fp, 0, ent, ent->db_name) == 1) {
        //     cb_print_ent(ent);
        // }
    } else {
        printf("n/a\n");
    }
}

void select_all_connector(FILE* fp, entrie* ent, void (*cb_print_ent)(entrie*)) {
    // init reading
    if (my_select(fp, ent->db_name, 1, comp_always_true, NULL, ent) == 1) {
        cb_print_ent(ent);
        while (my_select(fp, ent->db_name, 0, comp_always_true, NULL, ent) == 1) {
            cb_print_ent(ent);
        }
    } else {
        printf("n/a\n");
    }
}

void delete_connector(FILE* fp, entrie* ent) {
    int id;
    if (scan_id(&id, "id", get_db_name(ent->db_name)) == EOF)
        return;
    switch (my_delete(fp, ent->db_name, id)) {
        case 1: printf("success\n"); break;
        default: printf("n/a\n");
    }
}

void insert_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*)) {
    if (cb_scanf_ent(ent) == EOF)
        return;
    switch (my_insert(fp, ent->db_name, ent)) {
        case 1: printf("success\n"); break;
        default: printf("n/a\n");
    }
}

void update_connector(FILE* fp, entrie* ent, int (*cb_scanf_ent)(entrie*)) {
    int id;
    if (scan_id(&id, "id", get_db_name(ent->db_name)) == EOF)
        return;
    if (cb_scanf_ent(ent) == EOF)
        return;
    switch (my_update(fp, ent->db_name, id, ent)) {
        case 1: printf("success\n"); break;
        default: printf("n/a\n");
    }
}
