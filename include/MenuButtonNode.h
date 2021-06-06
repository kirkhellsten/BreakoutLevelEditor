#ifndef MENUBUTTONNODE_H
#define MENUBUTTONNODE_H

#include "MenuButton.h"
#include "MenuList.h"

enum MenuButtonNodeType { MBNT_BELOW, MBNT_LEFT, MBNT_RIGHT };

class MenuButtonNode : public MenuButton {

    public:
        MenuButtonNode(const char *text, MenuListOrientation menuListOrientation = MenuListOrientation::ML_HORIZONTAL);
        virtual ~MenuButtonNode();

        MenuList *menuList;
        MenuButtonNodeType menuButtonNodeType;

        void render();

    protected:

    private:

};

#endif // MENUBUTTONNODE_H
