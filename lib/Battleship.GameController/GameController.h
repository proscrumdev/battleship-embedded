#include <Letters.h>
#include <iostream>
#include <string>
#include <Ship.h>
#include <list>
#include <algorithm>
#include <time.h>

#ifndef GamesController_h
#define GamesController_h
class GameController {
    public:
        static bool CheckIsHit(list<Ship> &ships, Position shot);
        static Letters CharToLetter(char letter);
        static char LetterToChar(Letters letter);
        static list<Ship> InitializeShips();
        static Position GetRandomPosition(int size);
};
#endif