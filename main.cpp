
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>

#include "WidgetContainer.h"
#include "Pane.h"
#include "LevelArea.h"
#include "ToolKitArea.h"

const int FPS = 60;
const int LPS = 120;

using namespace std;

int main()
{
    srand (time(NULL));

    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_font_addon();
    al_install_audio();
    al_reserve_samples(16);
    al_init_image_addon();

    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);

    int displayWidth = 800;
    int displayHeight = 600;

    ALLEGRO_EVENT e;
    ALLEGRO_TIMER *FPSTimer = NULL;
    ALLEGRO_TIMER *LPSTimer = NULL;

    FPSTimer = al_create_timer(1.0 / FPS);
    LPSTimer = al_create_timer(1.0 / LPS);

    al_set_window_title(display, "Breakout Level Editor");
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(FPSTimer));
    al_register_event_source(eventQueue, al_get_timer_event_source(LPSTimer));
    al_register_event_source(eventQueue, al_get_mouse_event_source());


    al_start_timer(FPSTimer);
    al_start_timer(LPSTimer);


    //al_hide_mouse_cursor(display);


    bool isRunning = true;


    WidgetContainer *widgetContainer = new WidgetContainer(0, 0, displayWidth, displayHeight);
    //widgetContainer->addUIWidget(new LevelArea(0,20,600,400));
    widgetContainer->addUIWidget(new ToolKitArea(600,20,200,580));
    widgetContainer->start();

    while (isRunning) {
            al_wait_for_event(eventQueue, &e);

        if(e.timer.source == LPSTimer) {


        } else if (e.type == ALLEGRO_EVENT_MOUSE_AXES) {

        } else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {


        } else if(e.timer.source == FPSTimer) {

            al_set_target_backbuffer(display);
            al_clear_to_color(al_map_rgb(0,0,0));
            widgetContainer->render();
            al_flip_display();

        }

        if(e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isRunning = false;
        }

    }

    al_destroy_timer(FPSTimer);
    al_destroy_timer(LPSTimer);
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_shutdown_primitives_addon();
    al_uninstall_mouse();

    return 0;

}
