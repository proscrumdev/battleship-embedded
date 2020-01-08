#include <iostream>
#include <string>
#include <vector>
#include <Page.h>
using namespace std;

#ifndef DisplayManager_h
#define DisplayManager_h
class DisplayManager {
    public:
        vector<Page> OutputBuffer; 
        int CurrentPage=0;

    public:
        DisplayManager();
        int AddPage(Page page);
        Page & GetLastPage();
        Page & GetCurrentPage();
        Page & GetPage(int index);
        bool IsCurrentPageLastPage();
};
#endif