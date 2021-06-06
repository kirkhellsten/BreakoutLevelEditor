#ifndef PANE_H
#define PANE_H

#include "UIWidget.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>

using namespace std;

class Pane : public UIWidget {
    public:
        Pane(int x, int y, int width, int height, const char *title, int gridX=10, int gridY=10);
        virtual ~Pane();

        ALLEGRO_COLOR gridColor;
        float gridLineThickness;

        const char *title() const;
        ALLEGRO_COLOR titleBackgroundColor;
        ALLEGRO_COLOR titleBorderColor;
        int titleBorderThickness;

        ALLEGRO_BITMAP *contentAreaBackgroundBitmap;

        int titleHeight;

        int gridX;
        int gridY;

        void render();

    protected:
        void _renderGrid();
        void _renderTitleArea();
        void _renderContentArea();

        const char *_title;

    private:
};

#endif // PANE_H
