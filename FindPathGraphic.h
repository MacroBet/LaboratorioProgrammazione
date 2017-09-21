//
// Created by marco on 21/09/17.
//

#ifndef PATHFINDING_FINDPATHGRAPHIC_H
#define PATHFINDING_FINDPATHGRAPHIC_H


#include "MyWidget.h"
#include "GameMap.h"
#include "OptionMenu.h"
#include <list>
class FindPathGraphic :public Update {
public :
    virtual void repaint()override {
        window->clear(sf::Color::White);
        for(MyWidget* widget : widgets)
            widget->draw(window);
        window->display();
    }
    void buttonPressed(const std::string& text)override {
        optionMenu->onButtonPressed(text);
    }
    FindPathGraphic(int row,int col,int cellSize){
        map=new GameMap(this,row,col,cellSize,BORDER,0,0);
        optionMenu=new OptionMenu(this,map->getContentWidth(),60,BORDER,0,map->getRenderedHeight());
        addWidget(map);
        addWidget(optionMenu);
    }

    void openWindow(){
        window=new  sf::RenderWindow(sf::VideoMode(width,height), "My window");
        repaint();
        while (window->isOpen())
        {
            sf::Event event;
            if(event.type == sf::Event::MouseButtonPressed)
                pressed=true;
            if(event.type == sf::Event::MouseButtonReleased && pressed){
                pressed=false;
                //click action
                for(MyWidget* widget : widgets)
                    widget->userAction(event.mouseButton.x,event.mouseButton.y);
            }
            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed){
                    window->close();
                }
            }

        }
        delete window;

    }
private:
    sf::RenderWindow* window;
    OptionMenu* optionMenu;
    GameMap* map;
    const int BORDER=3;
    void addWidget(MyWidget* widget){
        if(widget!= nullptr){
            float wObj= widget->getRenderedWidth()+widget->getStartx();  //rendered width of widget
            float hObj= widget->getRenderedHeight()+widget->getStarty();  //rendered height of widget
            if(width<wObj)
                width=wObj;
            if(height<hObj)
                height=hObj;
            widgets.push_back(widget);
       }
    }
    bool pressed=false;
    float width=0,height=0;
    std::list<MyWidget*> widgets;

};


#endif //PATHFINDING_FINDPATHGRAPHIC_H
