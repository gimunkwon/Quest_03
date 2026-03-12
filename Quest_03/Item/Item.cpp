#include "Item.h"
#include <iostream>

using namespace std;

void item::printInfo() const
{
    cout << "[이름 : " << ItemName << ", 가격 : " << ItemPrice << "G]" << "\n";
}


