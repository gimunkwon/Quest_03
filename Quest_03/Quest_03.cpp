#include "Inventory/Inventory.h"
#include "Item/Item.h"
#include <iostream>
#include <vector>

using namespace std;


//TODO: 
// 데이터 보관함 Inventory<T> 클래스 설계
// 인벤토리 조작 기능
// 1. 아이템추가
// 2. 마지막 아이템 제거
// 3. 정보 조회 함수
// 4. 목록 출력 기능

// 구현해야하는 클래스
// 인벤토리,아이템,무기,포션

static int CurrentKeyNumber{1};


int main()
{
    Item* Gold = new Item("Gold",1000);
    Item* Sword = new Item("Sword",500);
    Item* Potion = new Item("Potion",200);
    
    Inventory<Item> inventory(30);

    while (CurrentKeyNumber != 0)
    {
        
    }
    
}