#include <iostream>
using namespace std;

class Math
{
public:
    static double Sin(double x)
    {
        return sin(x);
    }
};

class Vector
{
    int size;
    int* items;
public:
    Vector(int size) : size{ size }
    {
        //this->size = size;
        items = new int[size];
    }

    Vector() : Vector(0)
    {
        items = nullptr;
    }

    int Size() { return size; }

    void PushBack(int value)
    {
        int* itemsNew = new int[size + 1];
        for (int i = 0; i < size; i++)
            itemsNew[i] = items[i];
        itemsNew[size] = value;

        delete[]items;
        items = itemsNew;
        size++;
    }

    void SetItem(int index, int value)
    {
        items[index] = value;
    }

    int GetItem(int index)
    {
        return items[index];
    }

    int& At(int index)
    {
        return items[index];
    }

    int& operator[](int index)
    {
        return items[index];
    }

    ~Vector()
    {
        delete[]items;
    }
};

int main()
{
    srand(time(nullptr));

    Vector v;
    for (int i = 0; i < 10; i++)
        v.PushBack(rand() % 100);

    v[5] = 100;

    for (int i = 0; i < v.Size(); i++)
        cout << v[i] << " ";

    
}
