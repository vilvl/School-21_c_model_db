#include "main.h"

int levels_scan_entrie(entrie* ent) {
    if (scan_id(&ent->rec.id, "id") == EOF)
        return EOF;
    if (scan_id(&ent->rec.levels.cells, "cell") == EOF)
        return EOF;
    if (scan_id(&ent->rec.levels.protected, "protection") == EOF)
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
    FILE* fp = fopen(DB_LEVELS_PATH, "r+");
    entrie ent = {.db_name = LEVELS};
    switch (oper) {
        case INSERT: insert_connector(fp, &ent, levels_scan_entrie); break;
        case UPDATE: update_connector(fp, &ent, levels_scan_entrie); break;
        case DELETE: delete_connector(fp, &ent); break;
        case SELECT: select_connector(fp, &ent, levels_print_entrie); break;
    }
    fclose(fp);
}
