#include <iostream>
#include <string>
#include <Position.h>
#include <list>

#ifndef Ship_h
#define Ship_h
class Ship {
    public: 
        string Name;
        list<Position> Positions; 
        int Size;
        int Color;

    public:
        Ship();
        Ship(string name, int size, int Color);
        void AddPosition(Letters column, int row);

};
#endif