#include <iostream>
using namespace std;

//class Stack
//{
//    enum {EMPTY = -1, FULL = 9};
//    int arr[FULL + 1];//10
//    int topIndex;
//public:
//    Stack()
//    {
//        topIndex = EMPTY;
//    }
//    ~Stack() = default;
//    Stack(const Stack& other) = delete;
//    bool IsFull()const
//    {
//        return topIndex == FULL;
//    }
//    bool IsEmpty()const
//    {
//        return topIndex == EMPTY;
//    }
//    bool Push(int elem)
//    {
//        if (!IsFull())
//        {
//            arr[++topIndex] = elem;
//            return true;
//        }
//        return false;
//    }
//    int Pop()
//    {
//        if (!IsEmpty())
//            return arr[topIndex--];
//    }
//    int GetCount()const
//    {
//        return topIndex + 1;
//    }
//    int Peek()
//    {
//        if (!IsEmpty())
//            return arr[topIndex];
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }
//    void Print()const
//    {
//        for (int i = 0; i <= topIndex; i++)
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
class Stack
{
private:
	enum { EMPTY = -1 };
	int maxSize;
	int* arr;
	int topIndex;
public:
	Stack() = delete;
	Stack(int size) :maxSize(size)
	{
		arr = new int[size];
		topIndex = EMPTY;
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	bool IsFull()const
	{
		return topIndex == maxSize - 1;
	}
	bool Push(int value)
	{
		if (!IsFull())
		{
			arr[++topIndex] = value;
			return true;
		}
		else
		{

		}
		return false;
	}
	int Pop()
	{
		if (!IsEmpty())
			return arr[topIndex--];
		//else

	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	int Peek()
	{
		if (!IsEmpty())
			return arr[topIndex];
		//else
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i <= topIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void PrintTest()const
	{
		for (int i = 0; i < maxSize; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;


	}
	~Stack()
	{
		delete[]arr;
	}

};
bool IsValidCode(string code)
{
	Stack st(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st.Push(1);
		}
		if (symbol == '}')
		{
			if (st.IsEmpty())return false;
			st.Pop();
		}
	}
	return st.IsEmpty();
}

int main()
{
	string code = "class Stack{ void Print(){for(.....){if(.....){.....}}}};";
	if (IsValidCode(code))
		cout << "Valid code" << endl;
	else
		cout << "Invalid code" << endl;
	Stack st(10);
	st.Push(15);
	st.Print();
	st.PrintTest();
	cout << "Count : " << st.GetCount() << endl;
	st.Push(33);
	st.Push(2);
	st.Push(22);
	st.Push(11);
	st.Push(145);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	st.PrintTest();
	cout << "Element : " << st.Pop() << endl;
	st.Print();
	while (!st.IsEmpty())
	{
		cout << "Element : " << st.Pop() << endl;

	}
	cout << "Count : " << st.GetCount() << endl;

	//Stack st2(st);//copy ctor


}

