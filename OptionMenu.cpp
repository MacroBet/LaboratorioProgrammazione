//
// Created by marco on 21/09/17.
//

#include <iostream>
#include <assert.h>
#include "OptionMenu.h"
#include "exception"
void OptionMenu::draw(sf::RenderWindow *window) {
    MyWidget::draw(window);
    for(Button* button:buttons)
        button->draw(window);


    sf::Font font;
    sf::Text textView;
    assert(font.loadFromFile("arial.ttf"));
    textView.setFillColor(sf::Color::Black);
    textView.setPosition(startx+THICK*5,starty+height*7/10);
    textView.setFont(font);
    textView.setString(mode==-1?"":messages[mode]);
    textView.setCharacterSize(16);
    //text.setColor(sf::Color::Red);

    window->draw(textView);


}

void OptionMenu::userAction(int x, int y) {
    for(Button* button:buttons)
        button->userAction(x,y);

}
