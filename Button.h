//
// Created by marco on 21/09/17.
//

#ifndef PATHFINDING_BUTTON_H
#define PATHFINDING_BUTTON_H


#include "MyWidget.h"
#include <iostream>
class Button : public MyWidget{
public:
    Button(Update* update,float startx, float starty, float width,float height,std::string text,int textSize,int textWidth) :
            MyWidget(startx, starty, 0,update),width(width),height(height),text(text),textSize(textSize),selected(false),textWidth(textWidth){}

    virtual void userAction(int x,int y) override ;

    virtual void draw(sf::RenderWindow* window) override ;

    float getRenderedWidth() {
        return (unsigned int) width;
    }
    float getRenderedHeight() {
        return (unsigned int) height;
    }
    float getContentWidth(){
        return getRenderedWidth();
    }
    float getContentHeight(){
        return getRenderedHeight();
    }
    bool isSelected(){
        return selected;
    }
    void setNotSelected(){
        std::cout<<"sono "<<text<<std::endl;
        selected=false;
    }
private:
    float width,height,textSize;
    int textWidth;
    std::string text;
    bool selected;
};


#endif //PATHFINDING_BUTTON_H
