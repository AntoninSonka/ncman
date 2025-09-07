#include <stdio.h>
#include <stdlib.h>
#include "ncman.h"

int main(int argc, char* argv[]){
    Menu* menu = (Menu*) malloc(sizeof(Menu));
    menu = read_json_menu(menu, "../src/data/test.json");
    printf("header: %s\n", menu->header_text);
    printf("preview: %s\n", menu->preview_text);
    free(menu->header_text);
    free(menu->preview_text);
    free(menu);
    return 0;
}
