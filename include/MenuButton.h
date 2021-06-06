#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "UIWidget.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class MenuButton : public UIWidget {
    public:
        MenuButton(const char *text);
        virtual ~MenuButton();

        ALLEGRO_COLOR textBackgroundColor;
        ALLEGRO_COLOR textBorderColor;
        int textBorderThickness;

        void render();

        static const int MENU_BUTTON_WIDTH = 60;
        static const int MENU_BUTTON_HEIGHT = 20;

        vector<MenuButton*> *_menuList;

        const char *text();

    protected:

        const char *_text;

        void _renderButtonBackground();
        void _renderTextArea();

    private:
};

#endif // MENUBUTTON_H
