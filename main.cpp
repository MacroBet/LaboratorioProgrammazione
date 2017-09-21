#include <iostream>
#include <SFML/Graphics.hpp>
#include <exception>
#include "OptionMenu.h"

#include "GameMap.h"
#include "FindPathGraphic.h"


int main(){

    FindPathGraphic window(10,30,20);
    window.openWindow();
    return 0;
}

