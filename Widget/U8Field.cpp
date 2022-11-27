#include "U8Field.h"

#include "../Mouse/MouseObject.h"

#include <raylib.h>

U8Field::U8Field(int x, int y, int w, unsigned char* variableptr) : Widget(x, y, w, 16) {
    m_varriableptr = variableptr;
    m_tempvariable = *m_varriableptr;

    m_isselected = false;
    m_updaterealtime = true;

}

void U8Field::Update() {
    if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {    //deselect/confirm
        bool wasselected = m_isselected;
        m_isselected = false;

        if(wasselected) {
            (*m_varriableptr) = m_tempvariable;
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {       //select
            if(g_mouse->m_havebeenused == false) {
                if(g_mouse->m_x >= m_x && g_mouse->m_x < m_x + m_width
                && g_mouse->m_y >= m_y && g_mouse->m_y < m_y + m_height) {
                    m_isselected = true;
                    g_mouse->m_havebeenused = true;
                    m_tempvariable = (*m_varriableptr);
                }
            }
        }
    }

    if(m_isselected) {
        if(IsKeyPressed(KEY_UP)) {
            m_tempvariable+=1;
        }
        if(IsKeyPressed(KEY_DOWN)) {
            m_tempvariable-=1;
        }

        if(IsKeyPressed(KEY_BACKSPACE)) {
            m_tempvariable /= 10;
        }

        for(int i = KEY_KP_0; i < KEY_KP_9+1; i++) {
            if(IsKeyPressed(i)) {
                int newnumber = m_tempvariable * 10 + (i-320);

                if(newnumber >= 255) {
                    m_tempvariable = 255;
                }
                else {
                    m_tempvariable = newnumber;
                }
            }
        }

        if(m_updaterealtime) {
            (*m_varriableptr) = m_tempvariable;
        }
    }
}

void U8Field::Draw() {
    DrawRectangle(m_x, m_y, m_width, m_height, BLACK);

    if(m_isselected) {
        DrawRectangleLines(m_x, m_y, m_width, m_height, YELLOW);
        DrawText(TextFormat("%i", m_tempvariable), m_x + 2, m_y + 2, 10, WHITE);
    } else {
        DrawRectangleLines(m_x, m_y, m_width, m_height, WHITE);
        DrawText(TextFormat("%i", *m_varriableptr), m_x + 2, m_y + 2, 10, WHITE);
    }
}