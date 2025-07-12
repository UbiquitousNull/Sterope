#ifndef INPUT_H
#define INPUT_H

#define DEFAULT_CONTOLS = "../../../main/etc/saveData/defaultControls.ini"

#define MAX_LINE 15
#define MAX_KEY 50
#define MAX_VALUE 50

#include "main.h"

typedef struct {
    SDL_Keycode build_menu;
    SDL_Keycode crouch;
    SDL_Keycode exit;
    SDL_Keycode interact;
    SDL_Keycode inventory;
    SDL_Keycode modifier_key;
    SDL_Keycode move_backward;
    SDL_Keycode move_forward;
    SDL_Keycode move_left;
    SDL_Keycode move_right;
    SDL_Keycode sprint;
} ControlsK;

typedef struct {
    Uint8 click_primary;
    Uint8 click_secondary;
    SDL_MouseWheelDirection scroll_orientation;
} ControlsM;

void parse_ini_file(const char *filename, ControlsK *controls_k, ControlsM *controls_m);

#endif // INPUT_H