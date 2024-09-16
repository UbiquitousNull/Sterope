#include <stdio.h>
#include <string.h>
#include "fileRead.h"
#include "input.h"
#include "main.h"

/******************************************************************************************************************************************************************************/
/*
/*  Temporary file for `.ini` parsing *NOT FINAL*
/*
/******************************************************************************************************************************************************************************/ 


typedef struct {
    int build_menu;
    int crouch;
    int exit;
    int interact;
    int inventory;
    int modifier_key;
    int move_backward;
    int move_forward;
    int move_left;
    int move_right;
    int sprint;
} ControlsK;

typedef struct {
    int click_left;
    int click_right;
    int scroll_orientation;
} ControlsM;


int get_key_code(const char *key) {
    if (strcmp(key, "SDLK_F2") == 0) return SDLK_F2;
    if (strcmp(key, "SDLK_c") == 0) return SDLK_c;
    if (strcmp(key, "SDLK_ESCAPE") == 0) return SDLK_ESCAPE;
    if (strcmp(key, "SDLK_e") == 0) return SDLK_e;
    if (strcmp(key, "SDLK_TAB") == 0) return SDLK_TAB;
    if (strcmp(key, "SDLK_LCTRL") == 0) return SDLK_LCTRL;
    if (strcmp(key, "SDLK_s") == 0) return SDLK_s;
    if (strcmp(key, "SDLK_w") == 0) return SDLK_w;
    if (strcmp(key, "SDLK_a") == 0) return SDLK_a;
    if (strcmp(key, "SDLK_d") == 0) return SDLK_d;
    if (strcmp(key, "SDLK_LSHIFT") == 0) return SDLK_LSHIFT;
    
    if (strcmp(key, "SDL_BUTTON_LEFT") == 0) return SDL_BUTTON_LEFT;
    if (strcmp(key, "SDL_BUTTON_RIGHT") == 0) return SDL_BUTTON_RIGHT;
    if (strcmp(key, "SDL_MOUSEWHEEL_NORMAL") == 0) return SDL_MOUSEWHEEL_NORMAL;

    return -1; // Invalid key
}

void parse_controls_k(char *key, char *value, ControlsK *controls_k) {
    int key_code = get_key_code(value);

    if (strcmp(key, "build_menu") == 0) controls_k->build_menu = key_code;
    else if (strcmp(key, "crouch") == 0) controls_k->crouch = key_code;
    else if (strcmp(key, "exit") == 0) controls_k->exit = key_code;
    else if (strcmp(key, "interact") == 0) controls_k->interact = key_code;
    else if (strcmp(key, "inventory") == 0) controls_k->inventory = key_code;
    else if (strcmp(key, "modifier_key") == 0) controls_k->modifier_key = key_code;
    else if (strcmp(key, "move_backward") == 0) controls_k->move_backward = key_code;
    else if (strcmp(key, "move_forward") == 0) controls_k->move_forward = key_code;
    else if (strcmp(key, "move_left") == 0) controls_k->move_left = key_code;
    else if (strcmp(key, "move_right") == 0) controls_k->move_right = key_code;
    else if (strcmp(key, "sprint") == 0) controls_k->sprint = key_code;
}

void parse_controls_m(char *key, char *value, ControlsM *controls_m) {
    int key_code = get_key_code(value);

    if (strcmp(key, "click_left") == 0) controls_m->click_left = key_code;
    else if (strcmp(key, "click_right") == 0) controls_m->click_right = key_code;
    else if (strcmp(key, "scroll_orientation") == 0) controls_m->scroll_orientation = key_code;
}

void parse_ini_file(const char *DEFAULT_CONTROLS, ControlsK *controls_k, ControlsM *controls_m) {
    FILE *file = fopen(DEFAULT_CONTROLS, "r");
    if (!file) {
        printf("Error: Unable to open the .ini file.\n");
        return;
    }

    char line[256];
    char section[50] = "";
    while (fgets(line, sizeof(line), file)) {
        // Ignore comments
        if (line[0] == ';' || line[0] == '#') continue;

        // Check for section headers
        if (line[0] == '[') {
            sscanf(line, "[%49[^]]]", section);  // Read section name
        } else {
            // Parse key-value pairs
            char key[50], value[50];
            if (sscanf(line, "%49[^=]=%49s", key, value) == 2) {
                if (strcmp(section, "Controls-K") == 0) {
                    parse_controls_k(key, value, controls_k);
                } else if (strcmp(section, "Controls-M") == 0) {
                    parse_controls_m(key, value, controls_m);
                }
            }
        }
    }

    fclose(file);
}
