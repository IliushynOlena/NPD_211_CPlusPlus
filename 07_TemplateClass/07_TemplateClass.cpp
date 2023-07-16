#include <iostream>
using namespace std;

//int GetMax(int* arr, int size)
//{
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] > max)max = arr[i];
//	}
//	return max;
//}
//long GetMax(long* arr, int size)
//{
//	long max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] > max)max = arr[i];
//	}
//	return max;
//}
//short GetMax(short* arr, int size)
//{
//	short max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] > max)max = arr[i];
//	}
//	return max;
//}
template<typename T_arr>
T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

template<class T_coll, class T_value>
class MyClass
{
	int size;
	T_coll* collection;
	T_value value;
public:
	MyClass()
	{
		size = 0;
		collection = nullptr;
		//point = 0;
	}
	MyClass(T_coll* coll, T_value value) :collection(coll), value(value) {}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void SetCollection(T_coll* coll);	
	void SetValue(T_value value);	
	void Print()const
	{
		cout << "Collection : " << collection << endl;
		cout << "Point : " << value << endl;
	}
};

template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::SetCollection(T_coll* coll)
{
	collection = coll;
}

template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::SetValue(T_value value)
{
	this->value = value;
}
template<typename T_coord>
class Point
{
private:
	T_coord x;
	T_coord y;
public:
	Point()
	{
		x = y = 0;//<-
	}
	Point(T_coord value)
	{
		x = y = value;
	}
	Point(T_coord x, T_coord y) :x(x), y(y) {}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
};

template<typename T_X, typename T_Y>
class NewPoint
{
private:
	T_X x;
	T_Y y;
public:
	NewPoint()
	{
		x = y = 0;//<-
	}
	NewPoint(T_X value)
	{
		x = y = value;
	}
	NewPoint(T_X x, T_Y y) :x(x), y(y) {}
	void Print()const;
	
};
template<typename T_X, typename T_Y>
void NewPoint<T_X, T_Y>::Print()const
{
	cout << "X : " << x << " Y: " << y << endl;
}
int main()
{
	Point<int> p1(100, 150);
	p1.Print();

	Point<float> p2(0.145, 1.78);
	p2.Print();

	NewPoint<int, float> point1(15, 3.33);
	point1.Print();

	NewPoint<long long, double> point2(123546848677, 4.15);
	point2.Print();


	long* long_arr = new long[4];
	for (int i = 0; i < 4; i++)
	{
		long_arr[i] = i + 1;
		cout << long_arr[i] << " ";
	}
	cout << endl;

	char* char_arr = new char[4];
	for (int i = 0; i < 4; i++)
	{
		char_arr[i] = 'a' + i;
		cout << char_arr[i] << " ";
	}
	cout << endl;

	MyClass<long,string> cl1(long_arr, "Class with long collection");
	MyClass<char, string> cl2(char_arr, "Class with char collection");
	cl1.Print();
	cl2.Print();

	//delete[]long_arr;
	//delete[]char_arr;

	/*const int size = 10;
	int arr[size] = { 5,7,1,485,36,2,3,4,77,85 };
	cout << GetMax(arr, size) << endl;

	long arr2[size] = { 5,7,1,485,36,2,3,4,77,85 };
	cout << GetMax(arr2, size) << endl;

	short arr3[size] = { 5,7,1,48,363,2,3,4,77,85 };
	cout << GetMax(arr3, size) << endl;

	float arr4[size] = { 5.3,7,1,48,36.3,2,3,4,77,85 };
	cout << GetMax(arr4, size) << endl;*/


}

