#include <iostream>
using namespace std;

class Square;
class Rectangle
{
private:
    int h;
    int w;
public:
    Rectangle() : h(2), w(2) {}
    Rectangle(int v) : h(v), w(v) {}
    Rectangle(int h, int w) : h(h), w(w) {}
    void Show()const
    {
        cout << "Height : " << h << "  ";
        cout << "Width : " << w << endl;
    }
    //operator typename(){}//1
    //operator typename()const{}//2
    //explicit operator typename()const{}//3
    explicit operator int()
    {
        return w * h;
    }
    explicit operator Square();
     
};


class Square
{
private:
    int side;
public:
    Square() :side(2) {}
    Square(int s) :side(s) {}
    void Show()const
    {
        cout << "Height : " << side << "  ";
        cout << "Width : " << side << endl;
    }
    operator int()
    {
        return side * side;
    }
     operator Rectangle()
    {
        Rectangle rect(side, side + 10);
        return rect;
    }
};
Rectangle::operator Square()
{
    return Square(h + w);
}

int main()
{
    int valueInt = 9;
    double valDouble = valueInt;// int -> double implicit 9.0000000000 - standart - standart

    int a = 3.14;//double -> int implicit 3 - standart - standart
    int c = (int) valDouble;//explicit
    Square sq(5);//int -> Square - standart to abstract
    Rectangle rect(10, 15);//int -> Rectangle - standart to abstract
    sq.Show();
    rect.Show();
    valueInt = (int) rect;//abstract to standart
    cout << "Rectangle to int : " << valueInt << endl;

    rect = sq;//abstract to abstract
    rect.Show();

    sq = (Square) rect;//abstract to abstract
    sq.Show();
}

