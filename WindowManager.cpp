#include "WindowManager.h"

#include "Window.h"

WindowManager::WindowManager() {
    m_wincount = 0;
}

WindowManager::~WindowManager() {
    for(Window* w : m_windows) {
        delete w;
    }
    m_windows.clear();
    m_wincount = 0;

    EmptyTrashcan();
}

void WindowManager::Update() {
    for(unsigned int i = 0; i < m_wincount; i++) {
        m_windows[i]->MUpdate();
    }
}

void WindowManager::Draw() {
    for(int i = m_wincount - 1; i >= 0; i--) {
        m_windows[i]->Draw();
    }
}

void WindowManager::Add(Window* newwindow) {
    m_windows.push_back(newwindow);
    m_wincount++;

    newwindow->m_parrent = this;

    BringOnTop(newwindow);
}

void WindowManager::Remove(Window* windowptr) {
    for(unsigned int i = 0; i < m_wincount; i++) {
        if(m_windows[i] == windowptr) {
            m_trashcan.push_back(m_windows[i]);
            m_windows.erase(m_windows.begin() + i);
            m_wincount--;
            return;
        }
    }
}

Window* WindowManager::Get(unsigned int index) {
    if(index<m_wincount) {
        return m_windows[index];
    }
    return nullptr;
}

unsigned int WindowManager::GetWindowCount() {
    return m_wincount;
}

void WindowManager::BringOnTop(Window* windowptr) {
    for(unsigned int i = 0; i < m_wincount; i++) {
        if(m_windows[i] == windowptr) {
            for(int j = i-1; j >= 0; j--) {
                m_windows[j+1] = m_windows[j];
            }
            m_windows[0] = windowptr;
            return;
        }
        
    }
}

Window* WindowManager::FindWithID(int id) {
    for(unsigned int i = 0; i < m_wincount; i++) {
        if(m_windows[i]->m_id == id) {
            return m_windows[i];
        }
    }
    return NULL;
}

void WindowManager::EmptyTrashcan() {
    for(Window *w : m_trashcan) delete w;
    m_trashcan.clear();
}