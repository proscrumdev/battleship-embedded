#ifdef UNIT_TEST

#include <test_DisplayManager.h>
Page CreatePage(string suffix) {
    Page newPage;
    string line1 = suffix + "123456789";
    string line2 = suffix + "234567890";
    string line3 = suffix + "345678901";
    string line4 = suffix + "456789012";
    newPage.Line1 = line1;
    newPage.Line2 = line2;
    newPage.Line3 = line3;
    newPage.Line4 = line4;
    return newPage;
}

void test_AddingPage() {
    Page newPage = CreatePage("Page1_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(newPage);
    Page result = dm.GetLastPage();
    TEST_ASSERT_EQUAL_STRING(newPage.Line1.c_str(), result.Line1.c_str());
    TEST_ASSERT_EQUAL_STRING(newPage.Line4.c_str(), result.Line4.c_str());
}

void test_GetLastPageAsCurrentPage() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    Page result = dm.GetCurrentPage();
    TEST_ASSERT_EQUAL_STRING(page5.Line1.c_str(), result.Line1.c_str());
}

void test_GetCurrentPage() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    dm.CurrentPage=3;
    Page result = dm.GetCurrentPage();
    TEST_ASSERT_EQUAL_STRING(page3.Line3.c_str(), result.Line3.c_str());
}

void test_GetPageWithIndex() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    Page result = dm.GetPage(2);
    TEST_ASSERT_EQUAL_STRING(page2.Line3.c_str(), result.Line3.c_str());
}

void test_UpdateExistingPage() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    dm.GetPage(2).Line3 += "ABC";
    Page result = dm.GetPage(2);
    TEST_ASSERT_EQUAL_STRING((page2.Line3 + "ABC").c_str(), result.Line3.c_str());
}

void test_CurrentPageIsLastPage() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    bool result = dm.IsCurrentPageLastPage();
    TEST_ASSERT_TRUE(result);
}

void test_CurrentPageIsNotLastPage() {
    Page page1 = CreatePage("Page1_");
    Page page2 = CreatePage("Page2_");
    Page page3 = CreatePage("Page3_");
    Page page4 = CreatePage("Page4_");
    Page page5 = CreatePage("Page5_");
    DisplayManager dm = DisplayManager();
    dm.AddPage(page1);
    dm.AddPage(page2);
    dm.AddPage(page3);
    dm.AddPage(page4);
    dm.AddPage(page5);
    dm.CurrentPage = 4;
    bool result = dm.IsCurrentPageLastPage();
    TEST_ASSERT_FALSE(result);
}

int test_DisplayManager::runDisplayManagerTests( int argc, char **argv) {
    RUN_TEST(test_AddingPage);
    RUN_TEST(test_GetLastPageAsCurrentPage);
    RUN_TEST(test_GetCurrentPage);
    RUN_TEST(test_GetPageWithIndex);
    RUN_TEST(test_UpdateExistingPage);
    RUN_TEST(test_CurrentPageIsLastPage);
    RUN_TEST(test_CurrentPageIsNotLastPage);
}
#endif