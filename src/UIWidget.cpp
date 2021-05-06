#include "UIWidget.h"

UIWidget::UIWidget(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->bitmap = al_create_bitmap(width, height);
    this->backgroundColor = al_map_rgb(0,0,0);
    this->borderColor = al_map_rgb(0,0,0);
    this->backgroundBitmap = NULL;
}

UIWidget::~UIWidget() {

}

void UIWidget::render() {
    if (this->backgroundBitmap != NULL) {
        al_draw_bitmap(this->backgroundBitmap, this->x, this->y, NULL);
    }

    al_draw_rectangle(this->borderThickness, this->borderThickness,
                      this->width(), this->height(),
        this->borderColor, this->borderThickness);

    al_draw_bitmap(this->bitmap, this->x, this->y, NULL);
}

int UIWidget::width() const {
    return al_get_bitmap_width(this->bitmap);
}

int UIWidget::height() const {
    return al_get_bitmap_height(this->bitmap);
}
