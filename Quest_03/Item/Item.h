#pragma once

#include <string>
using namespace std;

class item
{
public:
    item() : ItemPrice(0), ItemName(""), ItemImage("[]"){}
    item(int price, string name, string ItemImage): ItemPrice(price), ItemName(name), ItemImage(ItemImage){}
    
    void printInfo() const;
    
    // Getter
    _forceinline  string GetItemName() const {return ItemName;}
    _forceinline  string GetItemImage() const {return ItemImage;}
    _forceinline  int GetItemPrice() const {return ItemPrice;}
private:
    int ItemPrice;
    string ItemName;
    string ItemImage;
};