#include <Ship.h>

int currentPosition = 0;

Ship::Ship(){
}

Ship::Ship(string name, int size, int color){
    Name = name;
    Size = size;
    Color = color;
}
void Ship::AddPosition(Letters column, int row)
{
    Position pos(column, row);
    Positions.insert(Positions.begin(), pos);
}

