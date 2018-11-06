#include <QCoreApplication>
#include <iostream>
#include <rover.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string line;
   int num1, num2;
   bool obstDetected = false;
   int i = 0;

   //input da tastiera per coordinate e direzione, valori default se linea blank
    int x,y,gridDimension; char dir;
    cout << "inserire coordinata x";
        try{
        getline(std::cin, line);
        x = stoi(line);

    }
        catch(exception ex){
          x = 0;
        }
    cout << "inserire coordinata y";
    try{
    getline(std::cin, line);
        y = stoi(line);
}
    catch(exception ex){
        y = 0;
    }
    cout << "inserire direzione iniziale";
    try{
    getline(std::cin, line);
    if ((line[0] == 'N') || (line[0] == 'S') || (line[0] == 'W') ||(line[0] == 'E') )
        dir = line[0];
    else
        dir = 'N';
    }
    catch(exception ex){
    dir = 'N';

    }
    Rover marsRover(x,y,dir);
    string roverMovement;

    cout << "inserire lunghezza della griglia";
    try{
        getline(std::cin, line);
        gridDimension = stoi(line);
    }
    catch(exception ex){
    gridDimension = 1;

    }

    //ostacoli random su griglia..
    srand((unsigned int)time(0));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    //inserimento stringa di comandi

    cout << "inserire stringa comandi, 'L' per sinistra, 'R' per destra, 'V' per traslare di spigolo, qualunque altro per lo spostamento";
    cin>>roverMovement;

    while ((i < roverMovement.size() ) && !obstDetected)
    {
      try{
        if(roverMovement[i]=='L'){
              marsRover.turnLeft();
         }
         else if(roverMovement[i]=='R')
              marsRover.turnRight();
        else if(roverMovement[i]=='V')
             marsRover.wrapping(gridDimension);
         else
             marsRover.movePos();
        obstDetected = marsRover.obstacleDetection(num1,num2);
        }
        catch(exception ex){
            cout << "inserire un comando valido ";
        }
        i++;
    }
    if (obstDetected)
            cout << "ostacolo trovato";
    marsRover.displayPosition();

    return a.exec();
}
