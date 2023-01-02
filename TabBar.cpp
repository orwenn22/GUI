#include "TabBar.h"

#include "MainWindow.h"
#include "Mouse/MouseObject.h"
#include "TabsHandler.h"
#include "Themes/ColorTheme.h"

#include <raylib.h>

TabBar::TabBar(TabsHandler* tabshandler) {
    m_tabshandler = tabshandler;

    m_tabwidth = 100;
    m_originx = 0;
}

TabBar::~TabBar() {

}

void TabBar::Update() {
    CheckOriginPosition();

    //Execute only if the mouse have not been used and if the mouse is overring the tabbar
    if(g_mouse->m_y > 20 || g_mouse->m_havebeenused == true) return;

    //Scroll throught the tabs
    int wheel = (int) GetMouseWheelMove();
    m_originx += wheel * 10;
    CheckOriginPosition();


    //switch between tabs + open new ones
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int endx = GetEndX();

        if(g_mouse->m_x < endx) {
            if(g_mouse->m_x < endx-20) {    //clicking on a tab
                int clickedtab = (g_mouse->m_x - m_originx) / m_tabwidth;
                SetSelectedTab(clickedtab);
            }
            else {      //clicking on new tab button
                OpenNewTab();
            }
        }
    }

    //Close tabs (middle click)
    if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
        int endx = GetEndX();

        if(g_mouse->m_x < endx-20) {
            int clickedtab = (g_mouse->m_x - m_originx) / m_tabwidth;
            m_tabshandler->CloseTab(clickedtab);
        }
    }

    //File drag and drop
    if(g_mouse->m_havefiles && g_mouse->m_fileslist.count == 1) {
            //g_mouse->m_fileslist.paths[0]
            m_tabshandler->OnFileDragAndDrop(std::string(g_mouse->m_fileslist.paths[0]));
        }
    
    g_mouse->m_havebeenused = true;
}

void TabBar::CheckOriginPosition() {
    int endx = GetEndX();
    if(endx < g_winwidth) m_originx += (g_winwidth - endx);     //maximum position of the tabs
    if(m_originx > 0) m_originx = 0;                            //minimum position of the tabs
}

//endx correspond to the absolute position of the right edge of the last tab + 20 pixel
int TabBar::GetEndX() {
    return m_originx + (GetTabCount() * 100) + 20;
}


void TabBar::Draw() {
    DrawRectangle(0, 0, g_winwidth, 20, g_colortheme.TabBarColor);
    DrawLine(0, 20, g_winwidth, 20, g_colortheme.OutlineColor);

    int selectedtab = GetSelectedTab();

    //Selected tabs
    DrawRectangle(selectedtab * m_tabwidth + m_originx, 0, m_tabwidth, 21, g_colortheme.SelectedTab);
    DrawLine(selectedtab * m_tabwidth + m_originx, 0, (selectedtab+1) * m_tabwidth + m_originx, 0, g_colortheme.OutlineColor);

    //lines / separators + tab titles
    int i;
    for(i = 0; i < GetTabCount(); i++) {
        DrawText(m_tabshandler->GetTabName(i).c_str(), m_originx + (i)*m_tabwidth + 2, 5, 10, g_colortheme.TextColor);

        DrawLine(m_originx + (i+1)*m_tabwidth, 0, m_originx+ (i+1)*m_tabwidth, 20, g_colortheme.OutlineColor);
    }

    //Last line for the new tab button
    DrawLine(m_originx + i*m_tabwidth + 20, 0, m_originx + i*m_tabwidth + 20, 20, g_colortheme.OutlineColor);
}


void TabBar::SetSelectedTab(int value) {
    m_tabshandler->SetSelectedTab(value);
}

int TabBar::GetSelectedTab() {
    return m_tabshandler->GetSelectedTab();
}

int TabBar::GetTabCount() {
    return m_tabshandler->GetTabCount();
}

void TabBar::OpenNewTab() {
    m_tabshandler->OpenNewTab();
}