#include "main.h"

int modules_scan_entrie(entrie* ent) {
    if (scan_id(&ent->rec.id, "id") == EOF)
        return EOF;
    if (scan_char(ent->rec.modules.name, 30, "module name (25 max len)") == EOF)
        return EOF;
    if (scan_id(&ent->rec.modules.lvl_id, "level") == EOF)
        return EOF;
    if (scan_id(&ent->rec.modules.cell, "level") == EOF)
        return EOF;
    if (scan_id(&ent->rec.modules.delete_flag, "level") == EOF)
        return EOF;
    return 0;
}


void modules_print_entrie(entrie* ent) {
    printf("%d %s %d %d %d\n",
        ent->rec.id,
        ent->rec.modules.name,
        ent->rec.modules.lvl_id,
        ent->rec.modules.cell,
        ent->rec.modules.delete_flag);
}

void modules_process_operation(enum operations oper) {
    FILE* fp = fopen(_DB_MODULES_PATH_, "r+");
    entrie ent = {.db_name = MODULES};
    switch (oper) {
        case INSERT: insert_connector(fp, &ent, modules_scan_entrie); break;
        case UPDATE: update_connector(fp, &ent, modules_scan_entrie); break;
        case DELETE: delete_connector(fp, &ent); break;
        case SELECT: select_connector(fp, &ent, modules_print_entrie); break;
    }
    fclose(fp);
}
