#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "Item/Item.h"



using namespace std;

template<typename T>
class inventory
{
public:
    inventory(int capacity = 10) : capacity_(capacity), size_(0),tittleBarcount(10)
    {
        pItems_ = new T[capacity_];
        
        if (capacity_ <= 0)
        {
            capacity_ = 1;
        }
        
    }
    inventory(const inventory<T>& other)
    {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i)
        {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 완료" << "\n";
    }
    ~inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
    }
#pragma region Functions
    // 아이템 추가 함수
    void AddItem(const T& item);
    // 마지막 아이템 제거 함수
    void RemoveLastItem();
    
    /** 인벤토리 조회 함수 **/
    // 인벤토리의 크기
    _forceinline int GetSize() const {return size_;}
    // 인벤토리의 최대 용량
    _forceinline  int GetCapacity() const {return capacity_;}
    
    // 인벤토리 아이템 목록 출력
    void printAllItem() const;
    // 인벤토리 GUI 출력
    void printInven() const;
    // 아이템 정렬 기능
    void SortItem();
    // 인벤토리 확장 기능
    void Resize();
    // 인벤토리 옮기기 기능
    void Assign(const inventory<T>& other);
#pragma endregion 
    
private:
    T* pItems_;
    int capacity_;
    int size_;
    int tittleBarcount;
    bool bIsAssign{true};
};

template <typename T>
void inventory<T>::AddItem(const T& item)
{
    if (size_ >= capacity_)
    {
        Resize();
    }
    pItems_[size_++] = item;
}

template <typename T>
void inventory<T>::RemoveLastItem()
{
    if (size_ <= 0)
    {
        cout << "인벤토리가 비어있습니다." << "\n";
        return;
    }
    cout << pItems_[--size_].GetItemName() << "이 삭제 되었습니다." << "\n";
    pItems_[size_] = T();
}

template <typename T>
void inventory<T>::printAllItem() const
{
    bool bIsstack = false;
    
    for (int i = 0; i < capacity_; i++)
    {
        
        if (pItems_[i].GetItemName() == "")
        {
            continue;
        }
        else
        {
            bIsstack = true;
            cout << i << "번슬롯 :"  << " ";
            pItems_[i].printInfo();
        }
    }
    
    if (!bIsstack)
    {
        cout << "인벤토리에 아무것도 들어있지 않습니다." << "\n";
    }
}

template <typename T>
void inventory<T>::printInven() const
{
    int j = 0;
    
    cout << "인벤토리" << "\n";
    for (int i = 0; i < capacity_ + tittleBarcount; i++)
    {
        if (i != 0 && i % 5 == 0)
        {
            cout << "\n";
        }
        if (i < 5)
        {
            cout << "==";
        }
        else if (i < capacity_ + tittleBarcount / 2)
        {
            if (pItems_[j].GetItemName() == "")
            {
                cout << "[]";
            }
            else
            {
                cout << "[" << pItems_[j].GetItemImage() << "]";
            }
            j++;
        }
        else
        {
            cout << "==";
        }
    }
    cout << "\n";
}

bool compareItemsByPrice(const item& a, const item& b)
{
    return a.GetItemPrice() < b.GetItemPrice();
}

template <typename T>
void inventory<T>::SortItem()
{
    if (size_ <= 0)
    {
        cout << "정렬할 아이템이 없습니다." << "\n";
        return;
    }
    
    sort(pItems_, pItems_ + size_, compareItemsByPrice);
    cout << "아이템 정렬 완료" << "\n";
}

template <typename T>
void inventory<T>::Resize()
{
    capacity_ *= 2;
    T* pNewItems = new T[capacity_];
    
    for (int i = 0; i < size_; i++)
    {
        pNewItems[i] = pItems_[i];
    }
    delete[] pItems_;
    pItems_ = pNewItems;
}

template <typename T>
void inventory<T>::Assign(const inventory<T>& other)
{
    if (!bIsAssign)
    {
        cout << "이미 인벤토리를 변경했습니다 더 이상 불가능 합니다." << "\n";
        return;
    }
        
    
    T* pPrevPItems = new T[capacity_];
    
    for (int i = 0; i < size_; i++)
    {
        pPrevPItems[i] = pItems_[i];
    }
    delete[] pItems_;
    
    pItems_ = other.pItems_;
    capacity_ = other.capacity_;
    
    for (int i = 0; i < size_; i++)
    {
        pItems_[i] = pPrevPItems[i];
    }
    
    bIsAssign = false;
    
    delete[] pPrevPItems;
}


