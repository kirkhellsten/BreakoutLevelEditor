#include "ToolKitArea.h"

ToolKitArea::ToolKitArea(int x, int y, int width, int height, const char *title) : Pane(x, y, width, height, title, 40, 20) {
    this->contentAreaBackgroundBitmap = al_load_bitmap("BrickBitmap.png");
}

ToolKitArea::~ToolKitArea() {

}
