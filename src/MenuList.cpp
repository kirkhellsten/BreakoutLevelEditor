#include "MenuList.h"

MenuList::MenuList(int x, int y, MenuListOrientation orientation) : UIWidget(x, y, 0, 0) {
    this->_menuButtons = new vector<MenuButton*>();
    this->backgroundColor = al_map_rgb(255, 255, 255);
    this->orientation = orientation;
}

MenuList::~MenuList() {

}

void MenuList::render() {
    UIWidget::render();
    // Go through all menu buttons and render them
    this->_renderMenuItems();
}

void MenuList::_renderMenuItems() {
    if (this->_menuButtons->size() > 0) {
        for(auto it = std::begin(*this->_menuButtons); it != std::end(*this->_menuButtons); ++it) {

            MenuButton *menuButton = (*it);
            menuButton->render();

            AH_set_target_bitmap(this->_bitmap);

            // Draw the menu item bitmap to menu list
            al_draw_bitmap(menuButton->bitmap(), menuButton->x(), menuButton->y(), 0);

            AH_set_original_bitmap();

        }
    }
}

void MenuList::addMenuItem(MenuButton *menuButton) {

    int lastButtonIndex = this->_menuButtons->size();

    if (this->orientation == MenuListOrientation::ML_HORIZONTAL) {
        menuButton->changePosition(lastButtonIndex * MenuButton::MENU_BUTTON_WIDTH, this->_y);
    } else if (this->orientation == MenuListOrientation::ML_VERTICAL) {
        menuButton->changePosition(this->_x, lastButtonIndex * MenuButton::MENU_BUTTON_HEIGHT);
    }

    this->_menuButtons->push_back(menuButton);
    this->__resizeMenuList();
}

void MenuList::__resizeMenuList() {

    // Recaclulate width and height of menu list based on number of menu buttons and orientation
    if (this->orientation == ML_HORIZONTAL) {
        UIWidget::resizeDimensions(this->_menuButtons->size()*MenuButton::MENU_BUTTON_WIDTH,
                                   MenuButton::MENU_BUTTON_HEIGHT);
    } else if (this->orientation == ML_VERTICAL) {
        UIWidget::resizeDimensions(MenuButton::MENU_BUTTON_WIDTH, this->_menuButtons->size()*MenuButton::MENU_BUTTON_HEIGHT);
    }

}
