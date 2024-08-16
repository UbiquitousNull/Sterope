#include <stdio.h>
#include "fileRead.h"
#include "input.h"
#include "main.h"

void parse_controls_k(char *key, char *value, ControlsK *controls_k) {
    if (strcmp(key, "build_menu") == 0) controls_k->build_menu = SDL_GetKeyFromName(value);
    else if (strcmp(key, "crouch") == 0) controls_k->crouch = SDL_GetKeyFromName(value);
    else if (strcmp(key, "exit") == 0) controls_k->exit = SDL_GetKeyFromName(value);
    else if (strcmp(key, "interact") == 0) controls_k->interact = SDL_GetKeyFromName(value);
    else if (strcmp(key, "inventory") == 0) controls_k->inventory = SDL_GetKeyFromName(value);
    else if (strcmp(key, "modifier_key") == 0) controls_k->modifier_key = SDL_GetKeyFromName(value);
    else if (strcmp(key, "move_backward") == 0) controls_k->move_backward = SDL_GetKeyFromName(value);
    else if (strcmp(key, "move_forward") == 0) controls_k->move_forward = SDL_GetKeyFromName(value);
    else if (strcmp(key, "move_left") == 0) controls_k->move_left = SDL_GetKeyFromName(value);
    else if (strcmp(key, "move_right") == 0) controls_k->move_right = SDL_GetKeyFromName(value);
    else if (strcmp(key, "sprint") == 0) controls_k->sprint = SDL_GetKeyFromName(value);
}

void parse_controls_m(char *key, char *value, ControlsM *controls_m) {
    if (strcmp(key, "click_primary") == 0) controls_m->click_primary = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
    else if (strcmp(key, "click_secondary") == 0) controls_m->click_secondary = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
    else if (strcmp(key, "scroll_orientation") == 0) {
        if (strcmp(value, "SDL_MOUSEWHEEL_NORMAL") == 0)
            controls_m->scroll_orientation = SDL_MOUSEWHEEL_NORMAL;
        else if (strcmp(value, "SDL_MOUSEWHEEL_FLIPPED") == 0)
            controls_m->scroll_orientation = SDL_MOUSEWHEEL_FLIPPED;
    }
}

void parse_ini_file(const char *DEFAULT_CONTOLS, ControlsK *controls_k, ControlsM *controls_m) {
    FILE *file = fopen(DEFAULT_CONTOLS, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE];
    char current_section[MAX_KEY] = "";
    while (fgets(line, sizeof(line), file)) {
        char *trim_line = strtok(line, "\n");  // Remove newline character
        if (trim_line[0] == '[') {
            sscanf(trim_line, "[%[^]]", current_section);
        } else if (trim_line[0] != ';' && trim_line[0] != '#' && trim_line[0] != '\0') {
            char key[MAX_KEY], value[MAX_VALUE];
            sscanf(trim_line, "%[^=]=%s", key, value);
            if (strcmp(current_section, "Controls-K") == 0) {
                parse_controls_k(key, value, controls_k);
            } else if (strcmp(current_section, "Controls-M") == 0) {
                parse_controls_m(key, value, controls_m);
            }
        }
    }
    fclose(file);
}