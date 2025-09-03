#include "../ncman.h"
#include <ncurses.h>
#include <cjson/cJSON.h>
#include <string.h>

Menu* read_json_menu(Menu* menu, const char path[]){
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
        menu->header_text = strdup(header->valuestring);
    }

    cJSON* preview = cJSON_GetObjectItemCaseSensitive(json, "preview");
    if(cJSON_IsString(preview) && (preview->valuestring != NULL)){
        menu->preview_text = strdup(preview->valuestring);
    }

    cJSON_Delete(json);
    
    return menu;
}
