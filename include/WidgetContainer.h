#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <iostream>
#include <vector>
#include "UIWidget.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class WidgetContainer {
    public:

        WidgetContainer(int x, int y, int width, int height);
        virtual ~WidgetContainer();

        void addUIWidget(UIWidget *widget);
        void start();

        ALLEGRO_BITMAP *bitmap() const;
        ALLEGRO_COLOR backgroundColor;
        ALLEGRO_COLOR borderColor;
        float borderThickness;

        int width() const;
        int height() const;

        void render();

    protected:

        ALLEGRO_BITMAP *_bitmap;
        int x, y;
        vector<UIWidget*> *widgets;

    private:

        static void *__LoopThreadFunc(ALLEGRO_THREAD *thr, void *arg);
        void __renderWidgets();

};

#endif // WIDGETCONTAINER_H
