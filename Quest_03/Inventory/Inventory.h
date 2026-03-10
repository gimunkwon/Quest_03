#pragma once

template <typename T>
class Inventory
{
public:
    Inventory(int capacity = 10) : capacity_{capacity}
    {
        if (capacity <= 0)
            capacity_ = 1;
        pItems_ = new T[capacity_];
    }
    ~Inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
    }
    void AddItem(const T& item);
    void RemoveLastItem();
    //Getter
    int Getsize() const;
    int GetCapacity() const;
    
    //Output
    void printInfo();
    void DrawInventory();
private:
    T* pItems_ = nullptr;
    // 인벤토리가 최대로 저장할 수 있는 공간의 크기
    int capacity_;
    // 현재 인벤토리에 저장된 아이템의 실제 개수
    int size_;
    
};

