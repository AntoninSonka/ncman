#ifndef NCMAN_H
#define NCMAN_H

#include <ncurses.h>
#include <cjson/cJSON.h>

typedef struct Menu Menu;       // holds windows (buttons and previews) and pointers to other Menus
                                // is allocated on the heap, so its programmers responsibility to free by function

typedef struct Record Record;   // Holds data from json file, which determens where record lives
                                // is allocated on the heap, so its programmers responsibility to free by function

struct Menu {
    Menu** options;
    WINDOW* header;
    WINDOW* preview;
    char* header_text;
    char* preview_text;

    Record** records;
};


struct Record {
    WINDOW* header;
    WINDOW* preview;
    char* header_text;
    char* preview_text;

    WINDOW* description;
    char* description_text;
};


// json/ncman_reader.c

Menu* read_json_menu(Menu*, const char[]);

Record* read_json_record(Record*, const char[]);

#endif // NCMAN_H
