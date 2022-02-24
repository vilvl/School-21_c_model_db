#include "main.h"

void turn_off_modules() {
    FILE* fp_mod = fopen(_DB_MODULES_PATH_, "r+");
    FILE* fp_event = fopen(_DB_EVENTS_PATH_, "r+");
    entrie cur = {.db_name = MODULES};
    entrie event;
    int ev_count = get_records_count_in_file(fp_event, EVENTS);
    if (my_select(fp_mod, cur.db_name, 1, comp_always_true, NULL, &cur) == 1) {
        event.db_name = EVENTS;
        event.rec.events.mod_id = cur.rec.id;
        event.rec.events.event_id = ++ev_count;
        event.rec.events.status = 0;
        get_cur_date_time(event.rec.events.date, event.rec.events.time);
        my_insert(fp_event, EVENTS, &event);
        while (my_select(fp_mod, cur.db_name, 0, comp_always_true, NULL, &cur) == 1) {
            event.db_name = EVENTS;
            event.rec.events.mod_id = cur.rec.id;
            event.rec.events.event_id = ++ev_count;
            event.rec.events.status = 0;
            get_cur_date_time(event.rec.events.date, event.rec.events.time);
            my_insert(fp_event, EVENTS, &event);
        }
         printf("success\n");
    } else {
        printf("n/a\n");
    }
    fclose(fp_mod);
    fclose(fp_event);
}


void delete_modules() {
    FILE* fp_mod = fopen(_DB_MODULES_PATH_, "r+");
    entrie cur = {.db_name = MODULES};
    if (my_select(fp_mod, MODULES, 1, comp_always_true, NULL, &cur) == 1) {
        cur.rec.modules.delete_flag = 1;
        if (cur.rec.id != 0)
            my_update(fp_mod, MODULES, cur.rec.id, &cur);
        while (my_select(fp_mod, cur.db_name, 0, comp_always_true, NULL, &cur) == 1) {
            cur.rec.modules.delete_flag = 1;
            if (cur.rec.id != 0)
                my_update(fp_mod, MODULES, cur.rec.id, &cur);
        }
        printf("success\n");
    } else {
        printf("n/a\n");
    }
    fclose(fp_mod);
}

void set_protection_for_main_module() {
    FILE* fp_event = fopen(_DB_EVENTS_PATH_, "r+");
    int ev_count = get_records_count_in_file(fp_event, EVENTS);
    entrie event = {.db_name = EVENTS, .rec.events.mod_id = 0};
    event.rec.events.status = 0;
    event.rec.events.event_id = ++ev_count;
    get_cur_date_time(event.rec.events.date, event.rec.events.time);
    my_insert(fp_event, EVENTS, &event);
    event.rec.events.status = 1;
    event.rec.events.event_id = ++ev_count;
    get_cur_date_time(event.rec.events.date, event.rec.events.time);
    my_insert(fp_event, EVENTS, &event);
    event.rec.events.status = 20;
    event.rec.events.event_id = ++ev_count;
    get_cur_date_time(event.rec.events.date, event.rec.events.time);
    my_insert(fp_event, EVENTS, &event);
    printf("success\n");
    fclose(fp_event);
}

void set_lvl_and_cell_for_main_module() {
    FILE* fp_mod = fopen(_DB_MODULES_PATH_, "r+");
    entrie event = {.db_name = MODULES, .rec.id = 0};
    if (my_select(fp_mod, MODULES, 1, comp_id_equality, &event, &event) == 1) {
        event.rec.modules.lvl_id = 1;
        event.rec.modules.cell = 1;
        my_update(fp_mod, MODULES, 0, &event);
        printf("success\n");
    } else {
        printf("n/a\n");
    }
    fclose(fp_mod);
}

void set_protection_by_lvl() {
    FILE* fp_mod = fopen(_DB_LEVELS_PATH_, "r+");
    entrie event = {.db_name = LEVELS, .rec.id = 1};
    if (my_select(fp_mod, MODULES, 1, comp_id_equality, &event, &event) == 1) {
        event.rec.levels.protected = 1;
        my_update(fp_mod, LEVELS, 1, &event);
        printf("success\n");
    } else {
        printf("n/a\n");
    }
    fclose(fp_mod);
}

void run_sequence() {
    printf("turning modules off...\n");
    turn_off_modules();
    printf("deleting modules...\n");
    delete_modules();
    printf("setting protection for the main module...\n");
    set_protection_for_main_module();
    printf("setting main module to 1st cell of 1st lvl...\n");
    set_lvl_and_cell_for_main_module();
    printf("set protection for 1st lvl...\n");
    set_protection_by_lvl();
}
