#include "UIWidget.h"

UIWidget::UIWidget(int x, int y, int width, int height) {
    this->_x = x;
    this->_y = y;
    this->_bitmap = al_create_bitmap(width, height);
    this->backgroundColor = al_map_rgb(0,0,0);
    this->borderColor = al_map_rgb(0,0,0);
    this->backgroundImageBitmap = NULL;
    this->borderThickness = 1;

    this->isBackgroundVisible = true;
    this->isBorderVisible = false;

}

UIWidget::~UIWidget() {

}

int UIWidget::x() {
    return this->_x;
}

int UIWidget::y() {
    return this->_y;
}

ALLEGRO_BITMAP *UIWidget::bitmap() {
    return this->_bitmap;
}

void UIWidget::render() {

    AH_set_target_bitmap(this->_bitmap);

    this->_renderBackground();
    this->_renderBorder();

    AH_set_original_bitmap();


}

void UIWidget::_renderBorder() {

    // 1st: Render Border
    if (this->isBorderVisible) {
        al_draw_rectangle(0, 0, this->width(), this->height(),
            this->borderColor, this->borderThickness);
    }

}

void UIWidget::_renderBackground() {

    if (isBackgroundVisible) {

        // 1st: Draw the Background Color
        al_draw_filled_rectangle(0, 0, this->width(), this->height(), this->backgroundColor);

        // 2nd: Draw Background Bitmap
        if (this->backgroundImageBitmap != NULL) {
            al_draw_bitmap(this->backgroundImageBitmap, 0, 0, NULL);
        }

    }

}

void UIWidget::resizeDimensions(int newWidth, int newHeight) {
    this->_bitmap = al_create_bitmap(newWidth, newHeight);
}

void UIWidget::changePosition(int newX, int newY) {
    this->_x = newX;
    this->_y = newY;
}

int UIWidget::width() const {
    return al_get_bitmap_width(this->_bitmap);
}

int UIWidget::height() const {
    return al_get_bitmap_height(this->_bitmap);
}
