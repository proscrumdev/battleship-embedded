#ifdef UNIT_TEST

#include <test_GameController.h>

void initializeFleet(list<Ship> &Fleet) {
    Fleet = GameController::InitializeShips();
    for_each(Fleet.begin(), Fleet.end(), [](Ship &ship) {
        if (ship.Name == "Aircraft Carrier") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 4));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 5));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 6));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 7));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 8));
        }
        if (ship.Name == "Battleship") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 6));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 7));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 9));
        }
        if (ship.Name == "Submarine") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::A, 3));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 3));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 3));
        }
        if (ship.Name == "Destroyer") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::F, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::G, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::H, 8));
        }
        if (ship.Name == "Patrol Boat") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 5));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 6));
        }
    });
}

void test_dummy() {
    TEST_ASSERT_EQUAL(1, 1);
}

void test_StringConcat() {
    int i = 23;
    string text = "Test ";

    string result = text + std::to_string(i);
    TEST_ASSERT_EQUAL_STRING("Test 23", result.c_str());
}

void test_CharToLetter_A() {
    char input = 'A';
    Letters actual = GameController::CharToLetter(input);
    TEST_ASSERT_EQUAL(Letters::A, actual);
}

void test_CharToLetter_B() {
    char input = 'B';
    Letters actual = GameController::CharToLetter(input);
    TEST_ASSERT_EQUAL(Letters::B, actual);
}

void test_PositionToString() {
    Position pos = Position(Letters::B, 3);
    string result = pos.toString();
    TEST_ASSERT_EQUAL_STRING("B3", result.c_str());
}

void test_ShouldHitShip() {
    list<Ship> fleet;
    initializeFleet(fleet);
    bool result = GameController::CheckIsHit(fleet, Position(Letters::A, 3));
    TEST_ASSERT_TRUE(result);
}

void test_ShouldNotHitShip() {
    list<Ship> fleet;
    initializeFleet(fleet);
    bool result = GameController::CheckIsHit(fleet, Position(Letters::A, 2));
    TEST_ASSERT_FALSE(result);
}

int test_GameController::runGameControllerTests( int argc, char **argv) {
    RUN_TEST(test_StringConcat);
    RUN_TEST(test_CharToLetter_A);
    RUN_TEST(test_CharToLetter_B);
    RUN_TEST(test_PositionToString);
    RUN_TEST(test_dummy);
    RUN_TEST(test_ShouldHitShip);
    RUN_TEST(test_ShouldNotHitShip);
    return 0;
}
#endif