#include "Pane.h"

Pane::Pane(int x, int y, int width, int height, const char *title, int gridX, int gridY) : UIWidget(x, y, width, height) {

    this->gridX = gridX;
    this->gridY = gridY;

    this->backgroundColor = al_map_rgb(50,50,50);
    this->borderColor = al_map_rgb(0,0,0);
    this->borderThickness = 1;
    this->gridColor = al_map_rgb(0,0,0);
    this->gridLineThickness = 1;
    this->titleHeight = 20;
    this->titleBorderThickness = 2;

    this->titleBackgroundColor = al_map_rgb(255, 255, 255);
    this->titleBorderColor = al_map_rgb(175, 175, 175);

    this->_title = title;
}

Pane::~Pane() {

}

void Pane::render() {

    UIWidget::render();

    AH_set_target_bitmap(this->_bitmap);

    this->_renderGrid();
    this->_renderTitleArea();
    this->_renderContentArea();

    AH_set_original_bitmap();

}

void Pane::_renderGrid() {

    for (int i = 1; i * this->gridX < this->width(); ++i) {
        al_draw_line(i * this->gridX, 0, i * this->gridX, this->height(),
           this->gridColor, this->borderThickness);
    }

    for (int ii = 1; ii * this->gridY < this->height(); ++ii) {
        al_draw_line(0, ii * this->gridY, this->width(), ii * this->gridY,
           this->gridColor, this->borderThickness);
    }

}

void Pane::_renderTitleArea() {

    static ALLEGRO_FONT *font = al_create_builtin_font();

    al_draw_filled_rectangle(0, 0, this->width(), this->titleHeight, this->titleBackgroundColor);
    al_draw_rectangle(0, 0, this->width() - this->titleBorderThickness,
                      this->titleHeight,
                      this->titleBorderColor, this->titleBorderThickness);
    al_draw_text(font, al_map_rgb(0, 0, 0), 5, 7, 0,
       this->_title);

}

void Pane::_renderContentArea() {
    if (this->contentAreaBackgroundBitmap != NULL) {
        al_draw_bitmap(this->contentAreaBackgroundBitmap, this->_x, this->_y+titleHeight, NULL);
    }
}

