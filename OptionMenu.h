//
// Created by marco on 21/09/17.
//

#ifndef PATHFINDING_OPTIONMENU_H
#define PATHFINDING_OPTIONMENU_H

#include <SFML/Graphics.hpp>
#include "MyWidget.h"
#include "Button.h"
#include <list>
class OptionMenu : public MyWidget {
public:
    OptionMenu(Update* update,unsigned int width,unsigned int height,int border,int startx, int starty): MyWidget(startx, starty,border,update),
            width(width),height(height){
        buttons.push_back(new Button(update,startx+border,starty+border,getRenderedWidth()/3,height/2.,names[0],16,34));
        buttons.push_back(new Button(update,startx+getRenderedWidth()/3,starty+border,getRenderedWidth()/3,height/2.,names[1],16,70));
        buttons.push_back(new Button(update,getRenderedWidth()*2/3-border,starty+border,getRenderedWidth()/3,height/2.,names[2],16,30));
    }
    void userAction(int x,int y);
    virtual void draw(sf::RenderWindow* window);

    virtual float getContentWidth(){
        return width;
    }
    virtual float getContentHeight(){
        return height;
    }
    void onButtonPressed(const std::string& text){
        int selected;
        for(int i=0;i<3;i++)
            if(text==names[i])
                selected=i;
        if (buttons[selected]->isSelected()){  //deseleziono tutto
            for(int i=0;i<3;i++)
                if(i!=selected)
                    buttons[i]->setNotSelected();
            mode=selected;
        }
        else
            mode=-1;
        updater->repaint();



    }
private:

    char mode=-1;
    const std::string names[3]{
            "Edit","From-To","Go!"
    };
    const std::string messages[3]{"Create your map, black is wall otherwhise empty",
                "Choose start node and end node",
                "I'm showing the best path between the selected nodes"};
    std::vector<Button*> buttons;
    unsigned int width,height;
};


#endif //PATHFINDING_OPTIONMENU_H
