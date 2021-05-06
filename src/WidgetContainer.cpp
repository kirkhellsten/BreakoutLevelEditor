#include "WidgetContainer.h"

WidgetContainer::WidgetContainer(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->_bitmap = al_create_bitmap(width, height);
    this->backgroundColor = al_map_rgb(50,50,50);
    this->borderColor = al_map_rgb(255,255,255);
    this->borderThickness = 1;
    this->widgets = new vector<UIWidget*>();
}

WidgetContainer::~WidgetContainer() {

}

void WidgetContainer::addUIWidget(UIWidget *widget) {
    this->widgets->push_back(widget);
}

void WidgetContainer::start() {
    ALLEGRO_THREAD *loopThread = al_create_thread(WidgetContainer::__LoopThreadFunc, this);
    al_start_thread(loopThread);
}

void WidgetContainer::__renderWidgets() {
    for (int i = 0; i < widgets->size(); ++i) {

        // Incase primitive drawing on ui widget occurs
        al_set_target_bitmap(this->_bitmap);

        UIWidget *uiWidget = (*widgets)[i];
        uiWidget->render();


    }
}

void *WidgetContainer::__LoopThreadFunc(ALLEGRO_THREAD *thr, void *arg) {
    WidgetContainer *wc = (WidgetContainer*) arg;

    ALLEGRO_MUTEX *mutex = al_create_mutex();
    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

    ALLEGRO_TIMER *wcFPSTimer = NULL;
    ALLEGRO_TIMER *wcLPSTimer = NULL;

    wcFPSTimer = al_create_timer(1.0 / 60);
    wcLPSTimer = al_create_timer(1.0 / 60);
    al_register_event_source(eventQueue, al_get_timer_event_source(wcFPSTimer));
    al_register_event_source(eventQueue, al_get_timer_event_source(wcLPSTimer));

    cout << "Entering new thread while loop " << endl;

    al_start_timer(wcFPSTimer);
    al_start_timer(wcLPSTimer);

   while(true) {

      al_lock_mutex(mutex);

        ALLEGRO_EVENT e;
        al_wait_for_event(eventQueue, &e);

        if(e.timer.source == wcFPSTimer) {


        } else if (e.timer.source == wcLPSTimer) {

        }


      al_unlock_mutex(mutex);

   }

   return NULL;
}

void WidgetContainer::render() {

    ALLEGRO_BITMAP *currentTargetBitmap = al_get_target_bitmap();
    al_set_target_bitmap(this->_bitmap);
    al_clear_to_color(this->backgroundColor);

    this->__renderWidgets();

    al_draw_rectangle(this->x+this->borderThickness, this->y, this->x + this->width(), this->y + this->height(),
        this->borderColor, this->borderThickness);

    al_set_target_bitmap(currentTargetBitmap);

    al_draw_bitmap(this->_bitmap, 0, 0, NULL);

}

ALLEGRO_BITMAP *WidgetContainer::bitmap() const {
    return this->_bitmap;
}

int WidgetContainer::width() const {
    return al_get_bitmap_width(this->_bitmap);
}

int WidgetContainer::height() const {
    return al_get_bitmap_height(this->_bitmap);
}
