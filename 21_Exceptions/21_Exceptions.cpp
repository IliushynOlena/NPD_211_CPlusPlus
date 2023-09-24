#include <iostream>
#include <exception>
using namespace std;

float Divide(float a, float b)
{
	

	// try catch throw
	float res = 0;
	//exception ex("Divide by zero!!!");
	if (b == 0)
	{
		cout << "Can't divide by zero!!!!" << endl;
		//throw ex;//work as return(break) , but don't return number
		throw exception("Divide by zero!!!");
	}
	if (b == 1)
	{
		throw 404;//int
	}
	if(b == 5)
	{
		throw "Divide by zero!!!";
	}
	if (b == 10)
	{
		throw 'A';//char ex
	}
	else
	{
		res = a / b;
		cout << "Res : " << res << endl;
		return res;
	}	
}

int main()
{
	float a, b;
	cout << "Enter a and b ";
	cin >> a >> b;
	try
	{
		float res = Divide(a, b);
		cout << "Res : " << res << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << "Page not found" << endl;
		cout << ex << endl;
	}
	catch (const char* ex) //char ex
	{
		cout << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}

	
   

	cout << "Continue......" << endl;
	cout << "Continue......" << endl;
	cout << "Continue......" << endl;
	cout << "Continue......" << endl;
	cout << "Continue......" << endl;
}

