#include "WindowCorner.h"

#include "MainWindow.h"
#include "Mouse/MouseObject.h"
#include "Themes/ColorTheme.h"

WindowCorner::WindowCorner(int minwidth, int minheight) {
    m_x = g_winwidth - 20;
    m_y = g_winheight - 20;

    m_followmouse = false;

    m_minwidth = minwidth;
    m_minheight = minheight;
}

void WindowCorner::Update() {
    m_x = g_winwidth - 20;
    m_y = g_winheight - 20;

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(g_mouse->m_x > m_x && g_mouse->m_y > m_y) {
            m_followmouse = true;

            m_mouseoffsetx = g_mouse->m_x - m_x;
            m_mouseoffsety = g_mouse->m_y - m_y;
        }
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        m_followmouse = false;
    }

    if(m_followmouse) {
        m_x = g_mouse->m_x - m_mouseoffsetx;
        m_y = g_mouse->m_y - m_mouseoffsetx;

        //Take the minimum size into account
        if(m_x < m_minwidth-20) {
            m_x = m_minwidth-20;
        }
        if(m_y < m_minheight-20) {
            m_y = m_minheight-20;
        }

        ResizeMainWindow(m_x+20, m_y+20);
    }

    if(g_mouse->m_x > m_x && g_mouse->m_y > m_y) {
        g_mouse->m_havebeenused = true;
    }
}

void WindowCorner::Draw() {
    DrawTriangle(
        (Vector2) {(float)(m_x)   , (float)(m_y+20 -1)},
        (Vector2) {(float)(m_x+20), (float)(m_y+20 -1)},
        (Vector2) {(float)(m_x+20), (float)(m_y    -1)},
        g_colortheme.CornerColor
    );

    DrawTriangleLines(
        (Vector2) {(float)(m_x)   , (float)(m_y+20 -1)},
        (Vector2) {(float)(m_x+20), (float)(m_y+20 -1)},
        (Vector2) {(float)(m_x+20), (float)(m_y    -1)},
        g_colortheme.OutlineColor
    );
}