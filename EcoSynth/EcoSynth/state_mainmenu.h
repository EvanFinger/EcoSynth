#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "state.h"
class state_mainmenu :
    public State
{
public:
    
    // constructor / destructor
    state_mainmenu(stateData* state_data);
    ~state_mainmenu();

    //update
    void updateInput();
    void update();
protected:

private:


};

#endif MAIN_MENU_H


