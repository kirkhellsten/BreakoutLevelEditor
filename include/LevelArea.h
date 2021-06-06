#ifndef LEVELAREA_H
#define LEVELAREA_H

#include "Pane.h"

class LevelArea : public Pane
{
    public:
        LevelArea(int x, int y, int width, int height, const char *title);
        virtual ~LevelArea();

    protected:

    private:
};

#endif // LEVELAREA_H
