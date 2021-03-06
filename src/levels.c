#include "main.h"

int levels_scan_entrie(entrie* ent) {
    if (scan_id(&ent->rec.id, "id", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_id(&ent->rec.levels.cells, "cell", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_id(&ent->rec.levels.protected, "protection", get_db_name(ent->db_name)) == EOF)
        return EOF;
    return 0;
}


void levels_print_entrie(entrie* ent) {
    printf("%d %d %d\n",
        ent->rec.id,
        ent->rec.levels.cells,
        ent->rec.levels.protected);
}

void levels_process_operation(enum operations oper) {
    FILE* fp = fopen(_DB_LEVELS_PATH_, "r+");
    entrie ent = {.db_name = LEVELS};
    switch (oper) {
        case INSERT: insert_connector(fp, &ent, levels_scan_entrie); break;
        case UPDATE: update_connector(fp, &ent, levels_scan_entrie); break;
        case DELETE: delete_connector(fp, &ent); break;
        case SELECT: select_connector(fp, &ent, levels_print_entrie); break;
        case SELECT_ALL: select_all_connector(fp, &ent, levels_print_entrie); break;
    }
    fclose(fp);
}
