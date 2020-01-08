#include "GameController.h"

bool GameController::CheckIsHit(list<Ship> &ships, Position shot)
{

    if (&ships == nullptr)
        throw std::invalid_argument(std::string("argument 'ships' is invalid"));

    for(Ship ship: ships) {
        for(Position position: ship.Positions) {
            if (position.Column == shot.Column && position.Row == shot.Row) {
                return true;
            }
        }
    }
    return false;
}

Letters GameController::CharToLetter(char input){
    return Letters(input-'A');
}

char GameController::LetterToChar(Letters input){
    return input+'A';
}

list<Ship> GameController::InitializeShips(){
    list<Ship> ships;
    ships.insert(ships.end(), Ship("Aircraft Carrier",5 ,44));
    ships.insert(ships.end(), Ship("Battleship", 4, 41));
    ships.insert(ships.end(), Ship("Submarine", 3, 42));
    ships.insert(ships.end(), Ship("Destroyer", 3, 43));
    ships.insert(ships.end(), Ship("Patrol Boat", 2, 45));
    return ships;
}

Position GameController::GetRandomPosition(int size) {
    srand((unsigned int) time(NULL));
    Letters lColumn = (Letters)(rand() % size);
    int nRow = (rand() % size);

    Position position(lColumn, nRow);
    return position;
}