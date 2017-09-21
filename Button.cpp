//
// Created by marco on 21/09/17.
//

#include <assert.h>
#include <iostream>
#include "Button.h"

void Button::userAction(int x,int y){
    MyWidget::decrementXY(x, y);
    std::cout<<"pesce"<<x<<" "<<y<<std::endl;
    if(x>=0 && x<this->width && y>=0 && y<height){
        std::cout<<"pesce vero "<<std::endl;
        selected=!selected;
        updater->buttonPressed(text);
    }
}
void Button::draw(sf::RenderWindow* window)  {
    sf::RectangleShape portraitB(sf::Vector2f(width,height));
    sf::RectangleShape portraitC(sf::Vector2f(width-THICK*2,height-THICK*2));
    sf::Font font;
    sf::Text textView;
    assert(font.loadFromFile("arial.ttf"));

    portraitB.setFillColor(sf::Color::Black);
    if(selected)
        portraitC.setFillColor(sf::Color(0, 230, 118, 200));
    else
        portraitC.setFillColor(sf::Color::White);
    portraitB.setPosition(startx,starty);
    portraitC.setPosition(startx+THICK,starty+THICK);
    textView.setFillColor(sf::Color::Black);
    textView.setPosition(startx+(width-textWidth)/2,starty+height/5);
    textView.setFont(font);
    textView.setString(text);
    textView.setCharacterSize(textSize);
    textView.setStyle(sf::Text::Bold);
    window->draw(portraitB);
    window->draw(portraitC);
    window->draw(textView);


};