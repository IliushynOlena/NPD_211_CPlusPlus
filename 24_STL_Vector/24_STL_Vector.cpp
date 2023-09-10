#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
    vector<int> v1;//default costructor
	cout << "Size v1 : " << v1.size() << endl;
	cout << "Capacity  v1: " << v1.capacity() << endl;
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };//ctor initializer list
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	vector<int> v2 = { 10,11,12,13,14 };
	
	for (int elem : v)
	{
		cout << elem << " ";
	}
	cout << endl;
	int a = 5;
	int* pa = &a;
	vector<int>::iterator vptr;
	//erase - you can delete element
	
	v.erase(v.begin());
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	//v.erase(v.begin()+1);
	//v.erase(v.begin()+4);
	//v.erase(v.end()-1);
	//v.erase(v.begin()+2, v.end()-3);

	//insert - add element by position
	v.insert(v.begin(), { 77,88,99 });
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), 5, 55);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin(), 999);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), v2.begin(), v2.end() - 2);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	//operator []
	v[0] = 100;
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.push_back(44);
	v.push_back(44);
	v.push_back(44);
	v.push_back(44);
	v.push_back(44);
	v.push_back(44);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.pop_back();
	v.pop_back();
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	/*Print(v);
	Print(v2);
	v.swap(v2);
	Print(v);
	Print(v2);*/
	cout<<"First element : " <<v.front()<<endl;
	cout<<"Last element : " <<v.back()<<endl;
	v.resize(50);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.push_back(333);
	Print(v);
	v.resize(20);
	v.shrink_to_fit();
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.push_back(44);
	v.push_back(44);
	v.push_back(44);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

		



}

