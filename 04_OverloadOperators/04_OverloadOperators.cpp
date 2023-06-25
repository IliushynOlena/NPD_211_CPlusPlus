#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;//<-
	}
	Point(int value)
	{
		x = y = value;
	}
	Point(int x, int y) :x(x), y(y) {}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
	Point Plus(const Point &other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point Minus(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	//Point operator[symbol](arguments)
	Point operator+(const Point& other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;

	}
	Point operator-(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	Point operator*(const Point& other)const
	{
		Point res(this->x * other.x, this->y * other.y);
		return res;
	}
	Point operator/(const Point& other)const
	{
		Point res(this->x / other.x, this->y / other.y);
		return res;
	}
	Point operator+(int value)const
	{
		Point res(this->x + value, this->y + value);
		return res;
	}
	Point operator +=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;//*address = Point(12,11);
	}
	Point operator-()const
	{
		//return Point(this->x*-1, this->y*-1);
		return Point(-x, -y);
	}
	Point operator =(const Point& other)
	{
		this->x = other.x;//10.....3
		this->y = other.y;//7.....2
		return *this;//*address = Point(12,11);
	}

	bool operator <(const Point& other)
	{
		/*if ((this->x + this->y) < (other.x + other.y))
			return true;
		else
			return false;*/

		return (this->x + this->y) < (other.x + other.y);
	}
	bool operator >(const Point& other)
	{
		return (this->x + this->y) > (other.x + other.y);
	}
	bool operator >=(const Point& other)
	{
		return (this->x + this->y) >= (other.x + other.y);
	}
	bool operator <=(const Point& other)
	{
		return (this->x + this->y) <= (other.x + other.y);
	}
	bool operator ==(const Point& other)
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	bool operator !=(const Point& other)
	{
		//return (this->x != other.x) || (this->y != other.y);
		return !(*this == other);
	}
};

int main()
{

 //   int a = 5;
	//a++;
	//a--;
	//int b = 4;
	//cout << a << " " << b << endl;
	//cout<< a + b<<endl;
	//cout << a << " " << b << endl;
	//cout<< a - b<<endl;
	//cout << (a != b) << endl;
	//cout << a;

	Point p1(10, 7);
	Point p2(2, 3);
	if (p1.operator<(p2))
	{
		cout << "p1 is smaller than p2" << endl;
	}
	else
	{
		cout << "p1 is not smaller than p2" << endl;
	}

	if (p1 > p2)
	{
		cout << "p1 is bigger than p2" << endl;
	}
	else
	{
		cout << "p1 is not bigger than p2" << endl;
	}
	if (p1 == p2)
	{
		cout << "points are equals" << endl;
	}
	else
	{
		cout << "points are not equals" << endl;
	}


	p1 = p2;
	//p1 += p2;
	Point res = p1.Plus(p2);

	res = -p1;
	cout << "Point 1: "; p1.Print();
	cout << "Point 2: "; p2.Print();
	cout << "Res: "; res.Print();
	res = p1.Minus(p2);
	cout << "Res: "; res.Print();
	res = p1 + p2; //p1.operator+(p2);
	cout << "Res: "; res.Print();
	res = p1 - p2; //p1.operator+(p2);
	cout << "Res: "; res.Print();
	res = p1 * p2; //p1.operator+(p2);
	cout << "Res: "; res.Print();
	res = p1 / p2; //p1.operator+(p2);
	cout << "Res: "; res.Print();
	res = p1 + 17; //p1.operator+(p2);
	//res = p1.operator+(17);
	cout << "Res: "; res.Print();

	

	/*cout << p1 + p2 << endl;
	cout << p1 - p2 << endl;
	cout << p1 * p2 << endl;*/
}

