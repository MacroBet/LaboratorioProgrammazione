//
// Created by marco on 21/09/17.
//

#ifndef PATHFINDING_UPDATE_H
#define PATHFINDING_UPDATE_H

#endif //PATHFINDING_UPDATE_H
#include <string>
class Update{
public:
    static const char MAP,BUTTON;
    virtual void repaint()=0;
    virtual void buttonPressed(const std::string& text)=0;
};