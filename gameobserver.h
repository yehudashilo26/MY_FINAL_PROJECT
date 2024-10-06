#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H

#include "events.h"
class GameObserver
{
public:
    GameObserver(){};
    ~GameObserver(){};

    virtual void onNotify(const Event &event){};
};

#endif // GAMEOBSERVER_H
