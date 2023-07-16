#include <iostream>
using namespace std;

class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const initializer_list<int> & list)
	{
		this->size = list.size();
		arr = new int[size];
		int i = 0;
		for (int element : list)
		{
			arr[i] = element;
			i++;
		}
	}
	void Fill(const initializer_list<int>& list)
	{
		if (arr != nullptr)delete[]arr;
		this->size = list.size();
		arr = new int[size];
		int i = 0;
		for (int element : list)
		{
			arr[i] = element;
			i++;
		}
	}
	void Print()const
	{
		cout << "Array (size = " << size << ") : ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int static_arr[5] = { 1,2,3,4,5 };
	int* dynam_arr = new int[5] {6, 7, 8, 9, 10};

	Array arr;
	arr.Print();
	Array arr2(10);
	arr2.Print();
	//Array arr3 = 5;//int -> Array - implicit - explicit
	//arr3.Print();
	Array arr4({ 1,2,3,4,5,6,7,8,9,10,10,20,30,40,50,60,70,80,90,100,200,300 });
	arr4.Print();
	arr4.Fill({ 5,4,3,2,1 });
	arr4.Print();

	delete[]dynam_arr;
   
}

