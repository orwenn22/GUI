#include "CppStringField.h"

#include "../Mouse/MouseObject.h"
#include "../Themes/ColorTheme.h"

#include <raylib.h>

#include <string>

CppStringField::CppStringField(int x, int y, int w, std::string* variableptr) : Widget(x, y, w, 16) {
    m_variableptr = variableptr;
    m_isselected = false;

    m_allowspace = true;
}

void CppStringField::Update() {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_isselected = false;

        if(g_mouse->m_havebeenused == false) {      //select
            if(g_mouse->m_x >= m_x && g_mouse->m_x < m_x + m_width
            && g_mouse->m_y >= m_y && g_mouse->m_y < m_y + m_height) {
                m_isselected = true;
                g_mouse->m_havebeenused = true;
            }
        }
    }

    if(m_isselected) {
        //Characters with uppercases
        for(int i = KEY_A; i < KEY_Z+1; i++) {
            if(IsKeyPressed(i)) {
                if(IsKeyDown(KEY_LEFT_SHIFT)) {
                    (*m_variableptr) += (char) i;
                }
                else {
                    (*m_variableptr) += (char) (i+32);
                }
                
            }
        }

        //Characters without uppercases
        for(int i = KEY_APOSTROPHE; i < KEY_EQUAL+1; i++) {
            if(IsKeyPressed(i)) {
                (*m_variableptr) += (char) i;
            }
        }

        if(IsKeyPressed(KEY_BACKSPACE)) {
            if(m_variableptr->size() > 0) {
                m_variableptr->erase(m_variableptr->begin() + m_variableptr->size() -1);
            }
        }

        if(IsKeyPressed(KEY_SPACE) && m_allowspace) {
            (*m_variableptr) += ' ';
        }
    }
}

void CppStringField::Draw() {
    DrawRectangle(m_x, m_y, m_width, m_height, g_colortheme->FieldBackground);
    DrawText(m_variableptr->c_str(), m_x + 2, m_y + 2, 10, g_colortheme->TextColor);

    if(m_isselected) {
        DrawRectangleLines(m_x, m_y, m_width, m_height, g_colortheme->FieldSelected);
    } else {
        DrawRectangleLines(m_x, m_y, m_width, m_height, g_colortheme->OutlineColor);
    }
}