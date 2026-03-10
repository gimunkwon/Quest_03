#pragma once
#include <string>
using namespace std;

class Item
{
public:
    Item(string Item_name, long Item_price) : ItemName{Item_name}, ItemPrice{Item_price} {} 
    
private:
    string ItemName;
    long ItemPrice;
};
