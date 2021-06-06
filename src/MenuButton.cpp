#include "MenuButton.h"

MenuButton::MenuButton(const char *text) : UIWidget(0, 0, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT) {
    this->_text = text;

    this->textBorderThickness = 2;

    this->textBackgroundColor = al_map_rgb(255, 255, 255);
    this->textBorderColor = al_map_rgb(175, 175, 175);

}

MenuButton::~MenuButton() {

}

void MenuButton::render() {
    UIWidget::render();

    AH_set_target_bitmap(this->_bitmap);

    this->_renderButtonBackground();
    this->_renderTextArea();

    AH_set_original_bitmap();

}

const char *MenuButton::text() {
    return this->_text;
}

void MenuButton::_renderButtonBackground() {
    al_draw_filled_rectangle(0, 0, this->width(), this->height(), this->textBackgroundColor);
    al_draw_rectangle(0, 0, this->width() - this->textBorderThickness,
                      this->height(),
                      this->textBorderColor, this->textBorderThickness);
}

void MenuButton::_renderTextArea() {

    static ALLEGRO_FONT *font = al_create_builtin_font();

    al_draw_text(font, al_map_rgb(0, 0, 0), 5, 7, 0,
       this->_text);

}
