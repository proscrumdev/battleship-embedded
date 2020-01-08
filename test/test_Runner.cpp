#ifdef UNIT_TEST

#include <unity.h>
#include <test_GameController.h>
#include <test_DisplayManager.h>

int main( int argc, char **argv) {
    UNITY_BEGIN();
    test_GameController gc = test_GameController();
    gc.runGameControllerTests(argc, argv);

    test_DisplayManager dm = test_DisplayManager();
    dm.runDisplayManagerTests(argc, argv);
    UNITY_END();
}
#endif