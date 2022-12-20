#include "MainWindow.h"

#include <raylib.h>

void ResizeMainWindow(int newwidth, int newheight) {
    if(newwidth != g_winwidth || newheight != g_winheight) {
        SetWindowSize(newwidth, newheight);
    }
}