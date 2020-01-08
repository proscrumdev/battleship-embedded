#include <iostream>
#include <string>
#include <Letters.h>

#ifndef Position_h
#define Position_h
class Position {
    public:
        Letters Column;
        int Row;

    public:
        Position();
        Position(Letters column, int row);
        string toString();

};
#endif