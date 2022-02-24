#include "main.h"

void welcome() {
    printf("\nPlease choose one operation:\n");
    printf("\t1. SELECT\n");
    printf("\t2. INSERT\n");
    printf("\t3. UPDATE\n");
    printf("\t4. DELETE\n");
    printf("\t5. Get all active additional modules (last module status is 1)\n");
    printf("\t6. Delete modules by ids\n");
    printf("\t7. Set protected mode for module by id\n");
    printf("\t8. Move module by id to specified memory level and cell\n");
    printf("\t9. Set protection flag of the specified memory level\n");
    printf("\t0. Exit\n");
    printf(PROMPT);
}

void welcome_choose_db() {
    printf("\nPlease choose a table:\n");
    printf("\t%d. Modules\n", MODULES);
    printf("\t%d. Levels\n", LEVELS);
    printf("\t%d. Status events\n", EVENTS);
    printf("\t0. Go back\n");
    printf(PROMPT);
}


void process_operation_on_db(enum operations oper, enum db_names db_name) {
    switch (db_name) {
        case MODULES: modules_process_operation(oper); break;
        case LEVELS: levels_process_operation(oper); break;
        case EVENTS: events_process_operation(oper); break;
    }
}

void choose_db(enum operations oper) {
    int mode = -1;
    int db_name = 0;
    while (mode && !db_name) {
        welcome_choose_db();
        if (!scan_int(&mode)) mode = -1;
        switch (mode) {
            case MODULES:
            case LEVELS:
            case EVENTS:
                process_operation_on_db(oper, mode); break;
            case 0: break;
            default: printf("n/a\n");
        }
    }
}

int main() {
    int mode = -1;
    while (mode) {
        welcome();
        if (!scan_int(&mode)) mode = -1;
        switch (mode) {
            case 1: choose_db(SELECT); break;
            case 2: choose_db(INSERT); break;
            case 3: choose_db(UPDATE); break;
            case 4: choose_db(DELETE); break;
            case 5: get_active_modeules(); break;
            case 6: delete_module_by_id(); break;
            case 7: set_protection_by_id(); break;
            case 8: set_lvl_and_cell_by_id(); break;
            case 9: set_protection_by_lvl(); break;
            case 0: break;
            default: printf("n/a\n");
        }
    }
    return 0;
}
