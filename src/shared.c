#include "main.h"

// 1 for success, -1 for error, 0 for no match
int my_select(FILE *fp, enum db_names db_name, int init,
        int (*comp)(entrie* etalon, entrie* peek),
        entrie* etalon, entrie* ret) {
    if (!fp)
        return -1;
    static int i;
    static int entrie_count;
    if (init) {
        i = 0;
        entrie_count = get_records_count_in_file(fp, db_name);
    }
    while (i < entrie_count) {
        entrie cur = read_record_from_file(fp, i++, db_name);
        if (comp(etalon, &cur)) {
            *ret = cur;
            return 1;
        }
    }
    return 0;
}

// 1 for success, -1 for error, 0 for no match
int my_delete(FILE *fp, enum db_names db_name, int id)  {
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
        ftruncate(fileno(fp), size_of_entrie(db_name) * entrie_count);
        return 1;
    }
    return 0;
}

// 1 for success, -1 for error
int my_insert(FILE *fp, enum db_names db_name, entrie *entity) {
    if (!fp)
        return -1;
    int entrie_count = get_records_count_in_file(fp, db_name);
    write_record_in_file(fp, entity, entrie_count, db_name);
    return 1;
}

// 1 for success, -1 for error, 0 for no match
int my_update(FILE *fp, enum db_names db_name, int id, entrie *entity) {
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
