//
// Created by marco on 21/09/17.
//

#ifndef PATHFINDING_MYWIDGET_H
#define PATHFINDING_MYWIDGET_H

#include <SFML/Graphics.hpp>
#include "Update.h"

class MyWidget{
protected:
    void decrementXY(int& x,int& y){
        x-=startx;
        y-=starty;
    }
public:
    static const int THICK=2;
    MyWidget(float startx, float starty,int border,Update* updater) : startx(startx), starty(starty),border(border),updater(updater) {}
    virtual void userAction(int x,int y)=0;
    virtual float getContentWidth()=0;
    virtual float getContentHeight()=0;
    virtual void draw(sf::RenderWindow* window){
        sf::RectangleShape portraitB(sf::Vector2f(THICK*2+border*2+getContentWidth(),
                                                  THICK*2+border*2+getContentHeight()));
        sf::RectangleShape portraitW(sf::Vector2f(border*2+getContentWidth(),
                                                  border*2+getContentHeight()));
        sf::RectangleShape* cell;
        portraitB.setFillColor(sf::Color::Black);
        portraitW.setFillColor(sf::Color::White);
        portraitB.setPosition(startx+border,starty+border);
        portraitW.setPosition(startx+border+THICK,starty+border+THICK);
        window->draw(portraitB);
        window->draw(portraitW);
    };
    virtual float getRenderedWidth()  {
        return (getContentWidth() + border * 4 + THICK * 2);
    }
    virtual float getRenderedHeight() {
        return (getContentHeight()+border*4 + THICK*2);
    }
    float getStartx(){
        return startx;
    }
    float getStarty(){
        return starty;
    }

protected:
    Update* updater;
    float starty;
    float startx;
    int border;
};
#endif //PATHFINDING_MYWIDGET_H
