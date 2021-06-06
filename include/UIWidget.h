#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "AllegroHelper.h"

using namespace std;

class UIWidget {
    public:
        UIWidget(int x, int y, int width, int height);
        virtual ~UIWidget();

        ALLEGRO_COLOR backgroundColor;
        ALLEGRO_COLOR borderColor;
        ALLEGRO_BITMAP *backgroundImageBitmap;

        float borderThickness;
        bool isBorderVisible;
        bool isBackgroundVisible;

        virtual void render();

        int width() const;
        int height() const;

        void resizeDimensions(int newWidth, int newHeight);
        void changePosition(int newX, int newY);

        int x(), y();

        ALLEGRO_BITMAP *bitmap();

    protected:

        int _x, _y;
        vector<UIWidget*> widgets;
        ALLEGRO_BITMAP *_bitmap;

        void _renderBackground();
        void _renderBorder();

    private:
};

#endif // UIWIDGET_H
