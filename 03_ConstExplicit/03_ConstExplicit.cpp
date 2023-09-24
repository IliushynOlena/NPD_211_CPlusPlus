#include <iostream>
using namespace std;

class Date
{
private:
    const int BaseYear;
    int& currentYear;
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y, int currentYear, int base) :BaseYear{ base }, currentYear(currentYear),
        day(d), month(m), year(y) {}
 
    //default construct
    //destructor
    //copy constructor
    //operator =
   /* Date(const Date &other)
    {

    }*/
    void SetDay(int day)
    {
        this->day = day;
    }
   /* void SetDay(Date* const this, int day)
    {
        this->day = day;
    }*/
    int GetDay()
    {
        return day;
    }
    int GetDay()const
    {
        return day;
    }
    void Print()
    {
        cout << "BaseYear : " << BaseYear << endl;
        cout << "Current year : " << currentYear << endl;
        cout << "day : " << day << endl;
        cout << "month : " << month << endl;
        cout << "year : " << year << endl;
    }
};

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double sum, double rate):rate(rate)
    {
        this->sum = sum;
        //this->rate = rate;
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome()const
    {
        return sum * rate / 100;
    }
    double getSum()
    {
        return sum;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};
void doSomething(long num) {}
float doSomething() { return 10.36; }//double => float

class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    explicit Array(const Array &other)
    {
        this->size = other.size;
        this->arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    ~Array()
    {
        delete[]arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int index, int value)
    {
        arr[index] = value;            
    }
    void Display(int index)const
    {
        cout << arr[index] << " ";
    }
};

void Print(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.Display(i);
    }
    cout << endl;
}
void Test(int a) {}
int main()
{
    //string hello = "hello";
    //Test(hello);
    int size = 8;
    //Array arr3 = 15;
    Array arr(size);//constructor
    for (int i = 0; i < size; i++)
    {
        arr.setValue(i, size - i - 1);
    }
    Print(arr);
    cout << "!!!!!!!!!!!!!!!!!!!!!" << endl;
    //Print(10);//int => Array - implicit
    Print(Array(15));//explicit
    Array arr2(arr);
    //Array arr2= arr;
    Print(arr2);

    float d = 3.1321564;
    int b = (float) d;

    //int c = 3.14;//double -> int - 3
    //cout << c << endl;
    //double a(10);//int -> double 10.000000000000
    //a = 15;
    //doSomething(15);//int=> long


   /* Account ac1(5000, 5);
    const  Account ac2(8000, 8);

    cout << "Get Rate 1 : " << ac1.getRate() << endl;
    cout << "Get Rate 2 : " << ac2.getRate() << endl;

    cout << "Get Sum 1 : " << ac1.getSum() << endl;
    cout << "Get Sum 2 : " << ac2.getSum() << endl;

    cout << "Get Income 1 : " << ac1.getIncome() << endl;
    cout << "Get Income 2 : " << ac2.getIncome() << endl;

    cout << "Set Sum 1 : " << ac1.setSum() << endl;*/
    //cout << "Set Sum 2 : " << ac2.setSum() << endl;error
    //const int size = 10;
    //const float PI;// = 3.14;
    //PI = 3.14;
    //cin >> PI;
    //int a = 10;
    //int* pa;// = &a;
    //pa = &a;
    //int& la = a;

    //const string str{ "first day" };
    //const char* s{ "C:\Test\test.txt" };
    //const int days[]{ 31,31,29 };
    ////days[0] = 20;

    //const Date eventDay( 26, 06, 2023, 2019,2000 );
    ////eventDay.SetDay(27);//error
    //cout<< "Day : "<<  eventDay.GetDay()<<endl;

    //int year;
    //cout << "Enter year: ";
    //cin >> year;
    //Date newDay(11, 01, 2001, 2023,year);
    //cout<< "Day : "<< newDay.GetDay()<<endl;
    //newDay.SetDay(1);
    //cout<< "Day : "<< newDay.GetDay()<<endl;
    //newDay.Print();
    //

}

