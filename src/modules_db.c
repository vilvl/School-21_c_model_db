#include "main.h"

void welcome() {
    printf("Please choose one operation:\n");
    printf("\t1. SELECT\n");
    printf("\t2. INSERT\n");
    printf("\t3. UPDATE\n");
    printf("\t4. DELETE\n");
    printf("\t5. Get all active additional modules (last module status is 1)\n");
    printf("\t6. Delete modules by ids\n");
    printf("\t7. Set protected mode for module by id\n");
    printf("\t8. Move module by id to specified memory level and cell\n");
    printf("\t9. Set protection flag of the specified memory level\n");
}

void choose_db() {
    printf("Please choose a table:\n");
    printf("\t1. Modules\n");
    printf("\t2. Levels\n");
    printf("\t3. Status events\n");
}

int main() {

    while (1) {
        int mode;
        welcome();
        if (!scan_int(&mode)) mode = -1;
        switch (mode) {
            case 1: SELECT(); break;
            case 2: INSERT(); break;
            case 3: UPDATE(); break;
            case 4: DELETE(); break;
            case 5: get_active_modeules(); break;
            case 6: delete_module_by_id(); break;
            case 7: set_protection_by_id(); break;
            case 8: set_lvl_and_cell_by_id(); break;
            case 9: set_protection_by_lvl(); break;
            default: printf("n/a\n");
        }
    }

    return 0;
}
