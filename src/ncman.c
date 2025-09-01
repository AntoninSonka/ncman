#include "ncman.h"
#include <ncurses.h>
#include <cjson/cJSON.h>

struct Menu {
    Menu** options;
    WINDOW* header;
    WINDOW* preview;
    char* header_text;
    char* preview_text;
};

Menu* read_json(Menu* menu, const char path[]){
    FILE* fp = fopen(path, "r");
    if(fp == NULL){
        printf("file read error\n");
        return NULL;
    }
    char buffer[1024];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    cJSON* json = cJSON_Parse(buffer);
    if(json == NULL){
        const char* error_ptr = cJSON_GetErrorPtr();
        if(error_ptr != NULL){
            printf("Error: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return NULL;
    }

    cJSON* header = cJSON_GetObjectItemCaseSensitive(json, "header");
    if(cJSON_IsString(header) && (header->valuestring != NULL)){
        printf("header: %s\n", header->valuestring);
    }
    cJSON_Delete(json);
    
    return menu;
}
