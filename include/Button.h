#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "UIWidget.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Button : public UIWidget {
    public:
        Button(int x, int y, const char *text);
        virtual ~MenuButton();

        ALLEGRO_COLOR titleBackgroundColor;
        ALLEGRO_COLOR titleBorderColor;
        int titleBorderThickness;

        void render();

        static const int MENU_BUTTON_WIDTH = 60;
        static const int MENU_BUTTON_HEIGHT = 20;

    protected:

        const char *_text;

        void _renderTitleArea();

    private:
};

#endif // MENUBUTTON_H
