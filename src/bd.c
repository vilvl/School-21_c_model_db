#include "main.h"

size_t size_of_entrie(db_name) {
    switch (db_name) {
        case LEVELS: return sizeof(struct levels_entrie);
        case MODULES: return sizeof(struct modules_entrie);
        case EVENTS: return sizeof(struct events_entrie);
    }
}

// Function of reading a record of a given type from a file by its serial number.
entrie read_record_from_file(FILE *pfile, int index, enum db_names db_name) {
    int offset = index * size_of_entrie(db_name);
    fseek(pfile, offset, SEEK_SET);
    entrie record;
    record.db_name = db_name;
    fread(&record.rec, size_of_entrie(db_name), 1, pfile);
    rewind(pfile);
    return record;
}

// Function of writing a record of the specified type to the file at the specified serial number.
void write_record_in_file(FILE *pfile, const entrie *record_to_write, int index, enum db_names db_name) {
    int offset = index * size_of_entrie(db_name);
    fseek(pfile, offset, SEEK_SET);
    fwrite(&record_to_write->rec, size_of_entrie(db_name), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

// Function of mutual transfer of two records in the file by their indexes.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2, enum db_names db_name) {
    if (record_index1 == record_index2)
        return;
    entrie record1 = read_record_from_file(pfile, record_index1, db_name);
    entrie record2 = read_record_from_file(pfile, record_index2, db_name);
    write_record_in_file(pfile, &record1, record_index2, db_name);
    write_record_in_file(pfile, &record2, record_index1, db_name);
}

// Function to get file size in bytes.
long get_file_size_in_bytes(FILE *pfile) {
    long size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

// Function to get count of records in file
long get_records_count_in_file(FILE *pfile, enum db_names db_name) {
    return get_file_size_in_bytes(pfile) / size_of_entrie(db_name);
}

