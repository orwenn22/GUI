#include "TabsHandler.h"

TabsHandler::TabsHandler() {

}

TabsHandler::~TabsHandler() {

}


void TabsHandler::SetSelectedTab(int value) {
    //Do something with value
}

int TabsHandler::GetSelectedTab() {
    return 0;
}


int TabsHandler::GetTabCount() {
    return 1;
}

void TabsHandler::OpenNewTab() {
    //Do something in subclass
}

void TabsHandler::CloseTab(int value) {
    //Do something in subclass
}

std::string TabsHandler::GetTabName(int value) {
    return std::to_string(value);
}

void TabsHandler::OnFileDragAndDrop(std::string filepath) {
    //Do something in subclass
}