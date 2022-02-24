#include "main.h"

int events_scan_entrie(entrie* ent) {
    if (scan_id(&ent->rec.id, "id", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_id(&ent->rec.events.mod_id, "module id", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_id(&ent->rec.events.status, "status", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_char(ent->rec.events.date, 11, "event date (DD.MM.YYYY)", get_db_name(ent->db_name)) == EOF)
        return EOF;
    if (scan_char(ent->rec.events.time, 10, "event time (HH:MM:SS)", get_db_name(ent->db_name)) == EOF)
        return EOF;
    return 0;
}


void events_print_entrie(entrie* ent) {
    printf("%d %d %d %s %s\n",
        ent->rec.id,
        ent->rec.events.mod_id,
        ent->rec.events.status,
        ent->rec.events.date,
        ent->rec.events.time);
}

void events_process_operation(enum operations oper) {
    FILE* fp = fopen(_DB_EVENTS_PATH_, "r+");
    entrie ent = {.db_name = EVENTS};
    switch (oper) {
        case INSERT: insert_connector(fp, &ent, events_scan_entrie); break;
        case UPDATE: update_connector(fp, &ent, events_scan_entrie); break;
        case DELETE: delete_connector(fp, &ent); break;
        case SELECT: select_connector(fp, &ent, events_print_entrie); break;
        case SELECT_ALL: select_all_connector(fp, &ent, events_print_entrie); break;
    }
    fclose(fp);
}
