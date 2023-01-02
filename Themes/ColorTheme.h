#ifndef COLOR_THEME_H
#define COLOR_THEME_H

#include <raylib.h>

struct ColorTheme {
    Color Background;

    Color WindowBackground;
    Color WindowClose;

    Color OutlineColor;
    Color OutlineSecondary;

    Color TextColor;

    Color BottomBarColor;
    Color CornerColor;

    Color TabBarColor;
    Color SelectedTab;

    Color FieldBackground;
    Color FieldSelected;

    Color ListBackground;
    Color ListSelection;

    Color ButtonBackground;
};

extern ColorTheme g_colortheme;

extern const ColorTheme DefaultDarkTheme;
extern const ColorTheme DefaultLightTheme;

#endif