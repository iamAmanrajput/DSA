#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;
    int z;

public:
    abc()
    {
        x = 0;
        y = new int(0);
    }

    abc(int _x, int _y, int _z = 0)
    {
        x = _x;
        *y = _y;
        z = _z;
    }

    int getX() const
    {
        return x;
    }

    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }

    int getZ() const
    {
        return z;
    }
};

void printAbc(const abc &a)
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{

    abc a(1, 2, 5);
    printAbc(a); // 1 2 5

    return 0;
}