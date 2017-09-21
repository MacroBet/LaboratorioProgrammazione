//
// Created by marco on 20/09/17.
//

#include "GameMap.h"

GameMap::GameMap(Update* update,int row, int col, int cellSize,int border,int startx,int starty) : MyWidget(startx,starty,border,update),
                            row(row),col(col), cellSize(cellSize) {
    map= new char*[col];
    for (int i = 0; i < col; ++i){
        map[i] = new char[row];
        for(int j=0;j<row;j++)
            map[i][j]=FREE;
    }


}

bool GameMap::addWall(int x, int y) {  //cells
    if(x>=0 && x<this->row && y>=0 && y<col){
        map[x][y]=WALL;
        updater->repaint();
        return true;
    }
    return false;
}

bool GameMap::addWall(int x,int y,bool horizontal,int lenght){
    bool done=false;
    if(x>=0 && x<this->row && y>=0 && y<col){
        if(horizontal){
            if((y+lenght)<col){ // add horizontal wall
                for(int i=0;i<lenght;i++)
                    map[x][y+i]=WALL;
                done=true;
            }
        }
        else{
            if((x+lenght)<row){ // add vertical wall
                for(int i=0;i<lenght;i++)
                    map[x+i][y]=WALL;
                done=true;
            }
        }
        updater->repaint();
    }
    return done;
}




void GameMap::userAction(int x, int y) {
    MyWidget::decrementXY(x, y);
    int totalTopBorder=border*2+THICK;
    if(x>=totalTopBorder && x<this->getRenderedWidth()-totalTopBorder*2 && y>=totalTopBorder && y<getRenderedHeight()-totalTopBorder*2){
        x-=totalTopBorder;
        y-=totalTopBorder;
        int row=x/cellSize,col=y/cellSize;
        if(map[row][col]==WALL)
            map[row][col]=FREE;
        else
            map[row][col]=WALL;
        updater->repaint();
    }
}

void GameMap::draw(sf::RenderWindow *window) {
    MyWidget::draw(window);
    int stx,sty;
    stx=startx+2*border+THICK;
    sty=starty+2*border+THICK;
    sf::RectangleShape wall(sf::Vector2f(cellSize, cellSize));
    sf::RectangleShape free(sf::Vector2f(cellSize, cellSize));
    sf::RectangleShape* cell;

    /*
    sf::RectangleShape portraitB(sf::Vector2f((cellSize*col)+border*2+THICK*2,
                                              (cellSize*row+border*2+THICK*2)));
    sf::RectangleShape portraitW(sf::Vector2f((cellSize*col)+border*2,
                                              (cellSize*row+border*2)));
    portraitB.setFillColor(sf::Color::Black);
    portraitW.setFillColor(sf::Color::White);
    portraitB.setPosition(startx+border,starty+border);
    portraitW.setPosition(startx+border+THICK,starty+border+THICK);
    window->draw(portraitB);
    window->draw(portraitW);*/
    wall.setFillColor(sf::Color::Black);
    free.setFillColor(sf::Color::Cyan);
    for(int i=0;i<col;i++)
        for(int j=0;j<row;j++){
            if(map[i][j]==FREE)
                cell=&free;
            if(map[i][j]==WALL)
                cell=&wall;
            cell->setPosition(stx+i*cellSize,sty+j*cellSize);
            window->draw(*cell);
        }

}
