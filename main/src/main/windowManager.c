/**
 * 
 *  This file is meant for management of all program windows
 *
 */

#include "windowManager.h"

static void initaliseWM(WindowManager* wm) { *wm = (WindowManager){0}; }

static void wm_destroy_window(WINDOW* w) {
    if (!w || !w->alive) return;
    if (w->context) destroyGLContext(w->context);
    if (w->window)  destroySDL2Window(w->window);
    *w = (WINDOW){0};
}

static void wm_free(WindowManager* wm) {
    for (size_t i = 0; i < wm->len; i++) wm_destroy_window(&wm->arr[i]);
    free(wm->arr);
    *wm = (WindowManager){0};
}

static WINDOW* wm_add(WindowManager* wm, WINDOW w) {
    if (wm->len == wm->cap) {
        size_t nc = wm->cap ? wm->cap * 2 : 4;
        void* p = realloc(wm->arr, nc * sizeof(WINDOW));
        if (!p) return NULL;
        wm->arr = (WINDOW*)p;
        wm->cap = nc;
    }
    wm->arr[wm->len] = w;
    return &wm->arr[wm->len++]; // NOTE: pointer invalidates after realloc later
}

static WINDOW* wm_find(WindowManager* wm, Uint32 id) {
    for (size_t i = 0; i < wm->len; i++)
        if (wm->arr[i].alive && wm->arr[i].id == id) return &wm->arr[i];
    return NULL;
}