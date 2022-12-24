#ifndef TABBAR_H
#define TABBAR_H

class TabsHandler;

class TabBar {
    public:
    TabBar(TabsHandler* tabshandler);
    virtual ~TabBar();

    void Update();
    void Draw();


    int m_tabwidth;
    int m_originx;

    int m_animovement;

    TabsHandler* m_tabshandler;


    private:
    void CheckOriginPosition();
    int GetEndX();

    void SetSelectedTab(int value);     //called when a tab is left-clicked
    int GetSelectedTab();

    int GetTabCount();

    void OpenNewTab();
};

#endif