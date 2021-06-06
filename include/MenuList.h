#ifndef MENULIST_H
#define MENULIST_H

#include "UIWidget.h"
#include "MenuButton.h"
#include <vector>
#include <iostream>

using namespace std;

enum MenuListOrientation { ML_HORIZONTAL, ML_VERTICAL };


class MenuList : public UIWidget {
    public:
        MenuList(int x, int y, MenuListOrientation orientation = ML_HORIZONTAL);
        virtual ~MenuList();

        void render();
        void addMenuItem(MenuButton *menuButton);

        MenuListOrientation orientation;

    protected:
        vector<MenuButton*> *_menuButtons;

        void _renderMenuItems();


    private:

        void __resizeMenuList();


};

#endif // MENULIST_H
