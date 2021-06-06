#include "MenuButtonNode.h"

MenuButtonNode::MenuButtonNode(const char *text, MenuListOrientation menuListOrientation) : MenuButton(text) {
    this->menuButtonNodeType = MenuButtonNodeType::MBNT_BELOW;
    this->menuList = new MenuList(this->_x, this->_y, menuListOrientation);
}

MenuButtonNode::~MenuButtonNode() {

}

void MenuButtonNode::render() {

    MenuButton::render();
    this->menuList->render();

    // Draw the menu item bitmap to menu list
    al_draw_bitmap(this->menuList->bitmap(), this->menuList->x(), this->menuList->y(), 0);

}
