#include<iostream>
#include<Windows.h>
#include<iomanip>

using namespace std;

void moveRectangle(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		static HANDLE h = NULL;
		if (!h)
			h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c = { x, y };
		SetConsoleCursorPosition(h, c);

	}
}

struct Coord
{
	int x;
	int y;
};

class MyRectangle
{
private:

	int height;
	int width;
	char symbol;
	Coord coord;

public:
	MyRectangle()
	{
		coord.x = 0;
		coord.y = 0;
		height = 4;
		width = 5;
		symbol = 3; //ascii code
	}

	MyRectangle(int size)
	{
		if (size >= 0)
		{
			coord.x = 0;
			coord.y = 0;
			height = size;
			width = size;
			symbol = 3;
		}
		else
			cout << "Error. Invalid size" << endl;
	}

	MyRectangle(int rectangleWidth, int rectangleHeight)
	{
		if (rectangleWidth >= 0 && rectangleHeight >= 0)
		{
			coord.x = 0;
			coord.y = 0;
			width = rectangleWidth;
			height = rectangleHeight;
			symbol = 3;
		}
		else
		{
			cout << "Error: Invalid width or height" << endl;
		}
	}

	void PrintRectangle()
	{
		for (int i = 0; i < height; i++)
		{
		    moveRectangle(coord.x, coord.y + i);//0 1
			for (int j = 0; j < width; j++)
			{
				cout << setw(3) << symbol;
			}
			cout << endl;
		}
		cout << endl;
	}

	void ChangeRectangle(int newHeight, int newWidth)
	{
		if (newHeight >= 0 && newWidth >= 0)
		{
			coord.x = 0;
			coord.y = 0;
			height = newHeight;
			width = newWidth;
		}
		else
		{
			cout << "Error: Invalid width or height" << endl;
		}
	}


	void setNewPosition(int x, int y)
	{
		this->coord.x = x;
		this->coord.y = y;
	}
};


void main()
{
	MyRectangle rectangle(6, 7);
	rectangle.PrintRectangle();

	rectangle.setNewPosition(15, 15);
	rectangle.PrintRectangle();

	/*rectangle.ChangeRectangle(5, 3);
	rectangle.PrintRectangle();*/


}
