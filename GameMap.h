//
// Created by marco on 20/09/17.
//

#ifndef PATHFINDING_GAMEMAP_H
#define PATHFINDING_GAMEMAP_H
#include <SFML/Graphics.hpp>
#include "MyWidget.h"

class GameMap : public MyWidget {
private :
    int row,col,cellSize;
    char **map;
    const char FREE=0,WALL=2;
public:

    GameMap(Update* update,int row, int col, int cellSize, int border,int startx=0,int starty=0);

    virtual float getContentWidth(){
        return cellSize*col;
    }
    virtual float getContentHeight(){
        return cellSize*row;
    }
    void userAction(int x,int y) override;
    bool addWall(int x,int y);
    bool addWall(int x,int y,bool horizontal,int lenght);
    void draw(sf::RenderWindow* window) override;
    ~GameMap(){
        for (int i = 0; i < row; ++i)
            delete [] map[i];
        delete [] map;
    }

};


#endif //PATHFINDING_GAMEMAP_H
