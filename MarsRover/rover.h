#ifndef ROVER_H
#define ROVER_H


class Rover
{
    int x;   //coordinate
    int y;
    char direction; //N,S,W,E

public:
    Rover();
    Rover( int , int , char );

    void movePos();
    void turnLeft();
    void turnRight();
    void wrapping(int);
    bool obstacleDetection(int, int);
    void displayPosition();

};

#endif // ROVER_H
