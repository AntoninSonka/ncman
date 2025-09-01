#ifndef NCMAN_H
#define NCMAN_H

#include <ncurses.h>
#include <cjson/cJSON.h>

typedef struct Menu Menu;       // holds windows (buttons and previews) and pointers to other Menus
                                // is allocated on the heap, so its programmers responsibility to free by function
struct Menu {
    Menu** options;
    WINDOW* header;
    WINDOW* preview;
    char* header_text;
    char* preview_text;
};

typedef struct Record Record;   // Holds data from json file, which determens where record lives
                                // is allocated on the heap, so its programmers responsibility to free by function

Menu* read_json(Menu*, const char[]);

#endif // NCMAN_H
