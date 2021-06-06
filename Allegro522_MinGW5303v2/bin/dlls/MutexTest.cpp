

#include "allegro5/allegro.h"

int main(int argc , char** argv) {

   if (!al_init()) {return -1;}
   
   ALLEGRO_MUTEX* m1 = al_create_mutex_recursive();
   ALLEGRO_MUTEX* m2 = al_create_mutex_recursive();

   ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
   
   al_uninstall_system();
   

   return 0;
}
