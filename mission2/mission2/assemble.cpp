#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include "Menu.hpp"

int main()
{
    Menu menu;

    return menu.Run();
}

#endif