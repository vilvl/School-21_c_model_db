#include "main.h"

// 1 for success, -1 for error, 0 for no match
int my_select(FILE *fp, int id, entrie* ent, enum db_names db_name) {
    if (!fp)
        return -1;
    int entrie_count = get_records_count_in_file(fp, db_name);
    for (int i = 0; i < entrie_count; ++i) {
        entrie cur = read_record_from_file(fp, i, db_name);
        if (cur.rec.id == id) {
            *ent = cur;
            return 1;
        }
    }
    return 0;
}

// 1 for success, -1 for error, 0 for no match
int my_delete(FILE *fp, int id, enum db_names db_name)  {
    if (!fp)
        return -1;
    int entrie_count = get_records_count_in_file(fp, db_name);
    int j = 0;
    for (int i = 0; i < entrie_count; ++i) {
        entrie cur = read_record_from_file(fp, i, db_name);
        // if not in range
        if (id != cur.rec.id) {
            if (j < i)
                write_record_in_file(fp, &cur, j, db_name);
            j++;
        }
    }
    if (j < entrie_count) {
        entrie_count = j;
        fflush(fp);
        ftruncate(fileno(fp), sizeof(entrie) * entrie_count);
        return 1;
    }
    return 0;
}

// 1 for success, -1 for error
int my_insert(FILE *fp, entrie *entity, enum db_names db_name) {
    if (!fp)
        return -1;
    int entrie_count = get_records_count_in_file(fp, db_name);
    write_record_in_file(fp, entity, entrie_count, db_name);
    return 1;
}

// 1 for success, -1 for error, 0 for no match
int my_update(FILE *fp, int id, entrie *entity, enum db_names db_name) {
    if (!fp)
        return -1;
    int entrie_count = get_records_count_in_file(fp, db_name);
    for (int i = 0; i < entrie_count; ++i) {
        entrie cur = read_record_from_file(fp, i, db_name);
        if (cur.rec.id == id) {
            write_record_in_file(fp, entity, i, db_name);
            return 1;
        }
    }
    return 0;
}
