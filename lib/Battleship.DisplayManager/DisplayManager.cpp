#include <DisplayManager.h>
using namespace std;

DisplayManager::DisplayManager(){
}

int DisplayManager::AddPage(Page page){
    OutputBuffer.insert(OutputBuffer.end(), page);
    CurrentPage++;
    return CurrentPage;
}

Page & DisplayManager::GetLastPage(){
    return OutputBuffer.back();
}

Page & DisplayManager::GetCurrentPage(){
    return OutputBuffer.at(CurrentPage-1);
}

Page & DisplayManager::GetPage(int index){
    return OutputBuffer.at(index-1);
}

bool DisplayManager::IsCurrentPageLastPage() {
    return CurrentPage == OutputBuffer.size();
}