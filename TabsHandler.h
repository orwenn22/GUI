#ifndef TABS_HANDLER_H
#define TABS_HANDLER_H

#include <string>

class TabsHandler {
    public:
    TabsHandler();
    virtual ~TabsHandler();

    virtual void SetSelectedTab(int value);     //called when a tab is left-clicked
    virtual int GetSelectedTab();

    virtual int GetTabCount();

    virtual void OpenNewTab();
    virtual void CloseTab(int value);

    virtual std::string GetTabName(int value);

    virtual void OnFileDragAndDrop(std::string filepath);

};

#endif