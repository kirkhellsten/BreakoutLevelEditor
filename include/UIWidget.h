#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class UIWidget {
    public:
        UIWidget(int x, int y, int width, int height);
        virtual ~UIWidget();

        ALLEGRO_COLOR backgroundColor;
        ALLEGRO_COLOR borderColor;
        ALLEGRO_BITMAP *backgroundBitmap;
        ALLEGRO_BITMAP *backgroundImageBitmap;

        float borderThickness;

        virtual void render();

        int width() const;
        int height() const;

    protected:

        int x, y;
        vector<UIWidget*> widgets;
        ALLEGRO_BITMAP *bitmap;

    private:
};

#endif // UIWIDGET_H
