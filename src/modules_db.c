#include "main.h"

void welcome() {
    printf("\nPlease choose one operation:\n");
    printf("\t1. SELECT\n");
    printf("\t2. SELECT ALL\n");
    printf("\t3. INSERT\n");
    printf("\t4. UPDATE\n");
    printf("\t5. DELETE\n");
    printf("\t6. Turn off additional modules\n");
    printf("\t7. Delete additional modules\n");
    printf("\t8. Set protected mode for main module\n");
    printf("\t9. Move main module level 1 and cell 1\n");
    printf("\t10. Set protection flag level 1\n");
    printf("\t11. Run full sequence\n");
    printf("\tCTRL+D to exit\n");
    printf(PROMPT);
}

void welcome_choose_db(enum operations oper) {
    printf("\n");
    printf("%s", get_oper_name(oper));
    printf(": Please choose a table:\n");
    printf("\t%d. Modules\n", MODULES);
    printf("\t%d. Levels\n", LEVELS);
    printf("\t%d. Status events\n", EVENTS);
    printf("\tCTRL+D to go back\n");
    printf(PROMPT);
}

void choose_db(enum operations oper) {
    int mode = 0;
    while (1) {
        welcome_choose_db(oper);
        if (scan_int(&mode) == EOF)
            break;
        switch (mode) {
            case MODULES: modules_process_operation(oper); break;
            case LEVELS: levels_process_operation(oper); break;
            case EVENTS: events_process_operation(oper); break;
            default: printf("n/a\n");
        }
    }
}

int main() {
    int mode = 0;
    while (1) {
        welcome();
        if (scan_int(&mode) == EOF)
            break;
        switch (mode) {
            case 1: choose_db(SELECT); break;
            case 2: choose_db(SELECT_ALL); break;
            case 3: choose_db(INSERT); break;
            case 4: choose_db(UPDATE); break;
            case 5: choose_db(DELETE); break;
            case 6: turn_off_modules(); break;
            case 7: delete_modules(); break;
            case 8: set_protection_for_main_module(); break;
            case 9: set_lvl_and_cell_for_main_module(); break;
            case 10: set_protection_by_lvl(); break;
            case 11: run_sequence(); break;
            case EOF: break;
            default: printf("n/a\n");
        }
    }
    return 0;
}
