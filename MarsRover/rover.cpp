#include "rover.h"
#include <iostream>
using namespace std;

Rover::Rover()
{
    x = 0;
    y = 0;
    direction = 'N';
}

Rover::Rover(int coordX, int coordY, char gridDir)
{
  try{
    x = coordX;
    y = coordY;
    direction = gridDir;
    }
    catch(exception ex){
        x = 0;
        y = 0;
        direction = 'N';
    }
}



void Rover::movePos(){
    switch (direction) {
        case 'N': y++; break;
        case 'W': x--; break;
        case 'S': y--; break;
        case 'E': x++; break;
    }
}

void Rover::turnLeft(){
    switch (direction) {
        case 'N': direction = 'W'; break;
        case 'W': direction = 'S'; break;
        case 'S': direction = 'E'; break;
        case 'E': direction = 'N'; break;
    }
}

void Rover::turnRight(){
        switch (direction) {
            case 'N': direction = 'E'; break;
            case 'W': direction = 'N'; break;
            case 'S': direction = 'W'; break;
            case 'E': direction = 'S'; break;
          }
       }
void Rover::displayPosition(){
    cout << " coordinate "<<x<<" "<<y<< " direzione " << direction;
}

void Rover::wrapping(int length){
    switch (direction){
    case 'N': y = y + length;  break;
    case 'W': x = x - length;  break;
    case 'S': y = y - length; break;
    case 'E': x = x + length; break;
   }
}

bool Rover::obstacleDetection(int obs1, int obs2){
    bool obstacle = false;
    if ((x == obs1) and (y == obs2))
        obstacle = true;
    return obstacle;
}

