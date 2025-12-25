#pragma once
#include <conio.h>
class towerchoicingInput
{
public:
    char getChar() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }

};

