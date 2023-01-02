#include "ColorTheme.h"


ColorTheme g_colortheme = DefaultLightTheme;

const ColorTheme DefaultDarkTheme = {
    .Background =       (Color) { 25,  25,  25, 255},
    .WindowBackground = (Color) { 15,  15,  15, 255},
    .WindowClose =      (Color) {230,  41,  55, 255},

    .OutlineColor =     (Color) {255, 255, 255, 255},
    .OutlineSecondary = (Color) {130, 130, 130, 255},

    .TextColor =        (Color) {255, 255, 255, 255},

    .BottomBarColor =   (Color) { 15,  15,  15, 255},
    .CornerColor =      (Color) { 15,  15,  15, 255},

    .TabBarColor =      (Color) { 15,  15,  15, 255},
    .SelectedTab =      (Color) { 25,  25,  25, 255},

    .FieldBackground =  (Color) { 25,  25,  25, 255},
    .FieldSelected =    (Color) {253, 249,   0, 255},

    .ListBackground =   (Color) { 25,  25,  25, 255},
    .ListSelection =    (Color) {230,  41,  55, 255},

    .ButtonBackground = (Color) { 25,  25,  25, 255}
};

const ColorTheme DefaultLightTheme = {
    .Background =       (Color) {220, 220, 220, 255},
    .WindowBackground = (Color) {240, 240, 240, 255},
    .WindowClose =      (Color) {230,  41,  55, 255},

    .OutlineColor =     (Color) {  0,   0,   0, 255},
    .OutlineSecondary = (Color) {130, 130, 130, 255},

    .TextColor =        (Color) {  0,   0,   0, 255},

    .BottomBarColor =   (Color) {240, 240, 240, 255},
    .CornerColor =      (Color) {240, 240, 240, 255},

    .TabBarColor =      (Color) {240, 240, 240, 255},
    .SelectedTab =      (Color) {220, 220, 220, 255},

    .FieldBackground =  (Color) {220, 220, 220, 255},
    .FieldSelected =    (Color) {253, 249,   0, 255},

    .ListBackground =   (Color) {220, 220, 220, 255},
    .ListSelection =    (Color) {230,  41,  55, 255},

    .ButtonBackground = (Color) {220, 220, 220, 255}
};