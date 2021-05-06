#include "ToolKitArea.h"

ToolKitArea::ToolKitArea(int x, int y, int width, int height) : Pane(x, y, width, height, 40, 20) {
    this->contentAreaBackgroundBitmap = al_load_bitmap("BrickBitmap.png");
}

ToolKitArea::~ToolKitArea() {

}
