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

static int CurrentKeynumber{1};
static int Choice_ItemNumber{};

int main()
{
    /* TEST용
    item Gold(1000, "Gold","●");
    item Sword(300, "Sword","↑");
    
    Inven.printInven();
    
    Inven.AddItem(Gold);
    Inven.AddItem(Sword);
    
    cout << "\n";
    Inven.printInven();
    Inven.printAllItem();
    
    cout << Inven.GetSize() << "\n";
    cout << Inven.GetCapacity() << "\n";
    */
    
#pragma region GameLoop
    inventory<item> Inven(5);
    inventory<item> Inven2(30);
    item Gold(1000,"Gold","●");
    item Sword(300, "Sword", "↑");

    bool bIsInvenOpen = false;
    
    while (CurrentKeynumber != 0)
    {
        if (bIsInvenOpen)
        {
            Inven.printInven();
        }
        
        cout << "==============" << "\n";
        cout << "0. 프로그램 종료" << "\n";
        cout << "1. 인벤토리 열기" << "\n";
        cout << "2. 인벤토리 아이템 목록 출력" << "\n";
        cout << "3. 인벤토리 최대용량" << "\n";
        cout << "4. 인벤토리에 들어있는 현재 아이템 갯수" << "\n";
        cout << "5. 아이템 추가" << "\n";
        cout << "6. 아이템 제거" << "\n";
        cout << "7. 아이템 정렬" << "\n";
        cout << "8. 인벤토리 변경" << "\n";
        cout << "==============" << "\n";
        
        cin >> CurrentKeynumber;
        
        switch (CurrentKeynumber)
        {
        case 0 :
            cout << "프로그램 종료";
            break;
        case 1 :
            bIsInvenOpen = true;
            break;
        case 2 :
            Inven.printAllItem();
            break;
        case 3 :
            cout << "인벤토리 최대용량: " << Inven.GetCapacity() << "\n";
            break;
        case 4 :
            cout << "인벤토리에 있는 아이템의 개수: " << Inven.GetSize() << "\n";
            break;
        case 5 :
            cout << "어떤 아이템을 추가 하시겠습니까?" << "\n";
            cout << "1. 검" << "\n";
            cout << "2. 골드" << "\n";
            cin >> Choice_ItemNumber;
            if (Choice_ItemNumber == 1)
            {
                Inven.AddItem(Sword);
            }
            else if (Choice_ItemNumber == 2)
            {
                Inven.AddItem(Gold);
            }
            break;
            
        case 6 :
            Inven.RemoveLastItem();
            break;
        case 7 :
            Inven.SortItem();
            break;
        case 8:
            Inven.Assign(Inven2);
            break;
        }
    }
#pragma endregion
    
}