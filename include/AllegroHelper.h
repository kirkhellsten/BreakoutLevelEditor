#ifndef ALLEGROHELPER_H_INCLUDED
#define ALLEGROHELPER_H_INCLUDED

#include <allegro5/allegro.h>
#include <vector>

using namespace std;

inline void AH_set_target_bitmap(ALLEGRO_BITMAP *bitmap);
inline void AH_set_original_bitmap();

static vector<ALLEGRO_BITMAP*> *__TARGET_BITMAP_CONTAINER__;

void AH_set_target_bitmap(ALLEGRO_BITMAP *bitmap) {
    //ALLEGRO_LOCKED_REGION *lock = al_lock_bitmap(bitmap, 0, 0);

    if (__TARGET_BITMAP_CONTAINER__ == NULL) {
        __TARGET_BITMAP_CONTAINER__ = new vector<ALLEGRO_BITMAP*>();
    }

    __TARGET_BITMAP_CONTAINER__->push_back(al_get_target_bitmap());
    al_set_target_bitmap(bitmap);

}

void AH_set_original_bitmap() {
    //al_unlock_bitmap(__TARGET_BITMAP__);
    al_set_target_bitmap(__TARGET_BITMAP_CONTAINER__->at(__TARGET_BITMAP_CONTAINER__->size() - 1));
    __TARGET_BITMAP_CONTAINER__->pop_back();
}

#endif // ALLEGROHELPER_H_INCLUDED
