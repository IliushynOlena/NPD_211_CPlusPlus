#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

class Person
{
private:
	string name;//Victor
	int age;//15
	int* marks;//00x15HGU4
	int marksCount;//4

public:
	// Конструктор - метод, який викликається автоматично при створенні об'єкта класу.
	// Використовується для ініціалізації полів

	// Конструктора за замовчуванням (default ctor) - без параметрів
	Person()
	{
		name = "";
		age = 0;
		marks = nullptr;
		marksCount = 0;
	}

	// Параметризований конструктор - який приймає якісь параметри
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	// Деструктор - метод, який викликається автоматично при видаленні об'єкта класу
	// Використовується для очищення пам'яті, звільнення ресурсів і тд.
	~Person()
	{
		if (marks != nullptr)
			delete[] marks;
		cout << "Destructor [" << name << "]...\n";
	}


	void Print() const // константний метод, який не змінює властивості класа
	{
		cout << "-------- STUDENT [" << name << "] ---------\n";
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (size_t i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void AddMark(int value)
	{
		int* new_arr = new int[marksCount + 1];
		for (size_t i = 0; i < marksCount; ++i)
		{
			new_arr[i] = marks[i];
		}
		new_arr[marksCount] = value;
		if (marks != nullptr)
			delete[] marks;
		marks = new_arr;

		++marksCount;
	}
	Person(const Person &other)
	{
		this->name = other.name;//Victor
		this->age = other.age;//15
		//copy pointer
		//this->marks = other.marks;//00x15JHG - error
		this->marks = new int[other.marksCount];
		for (int i = 0; i < other.marksCount; i++)
		{
			marks[i] = other.marks[i];
		}
		this->marksCount = other.marksCount;//4

	}

};
struct Data
{
	//public
	int day;
	int month;
	int year;
};
class Human
{
	//private:
	string name;
	int age;
	int weight;
	Data birthday;


	static int count;
public:
	static int getCount()
	{
		return count;
	}
	void Test()
	{
	
		int a = 5;
		cout << a << endl;
	}
	Human() :name{ "" }, age{ 0 }, weight{ 0 } { count++; }
	//Human() :name(""), age( 0 ), weight( 0 ) {}
	/*{
		name = "";
		age = 0;
		weight = 0;
	}*/
	Human(string name) : Human()
	{
		this->name = name;
		//age = 0;
		//weight = 0;
	}
	Human(string name, int age):Human(name)
	{
		//this->name = name;
		this->age = age;
		//weight = 0;
	}
	Human(string name, int age, int weight):Human(name,age)
	{

		//this->name = name;
		//this->age = age;
		this->weight = weight;
	}
	void Show()const
	{
		
		//this->age = 10;
		//cout << this->age << endl;
		//name = "Ivan";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Weight : " << weight << endl;
		cout << "Count : " << count << endl;
	}
	~Human()
	{
		count--;
	}
};

int Human::count = 0;

int main()
{
	Human::getCount();
	
	Human h;
	h.getCount();

	h.Show();
	Human h2("Petro");

	h2.Show();
	Human h3("Ivan", 12);
	h3.Show();
	if (true)
	{
		Human h4("Ivanka", 17, 44);
		h4.Show();
	}
	
	

	cout << "Count human : " << h.getCount() << endl;
	cout << "Count human : " << h2.getCount() << endl;
	cout << "Count human : " << h3.getCount() << endl;
	cout << "Count human : " << Human::getCount() << endl;

	/*
	Student testSt;					// виклик конструктора за замовчуванням
	Student st("Viktor", 15);	// виклик параметризованого конструктора

	st.AddMark(8);
	st.AddMark(7);
	st.AddMark(11);
	st.AddMark(10);


	st.Print();
	{
		Student copy = Student(st);
		copy.Print();
	}
	*/
    /*
    int a;//4b
    int b = 10;
    int c = 3.33;
    //cout << a << endl;
    cout << b << endl;
    cout << c << endl;


    int arr[2];
    arr[0] += 2;
    cout << arr[0] << endl;

    int number = 0.33;//initialization with copy
    cout << number << endl;
    int value(42.33);//пряма initialization
    cout << value << endl;
    int size{ 33.33 };
    cout << size << endl;
    //cout << "Hello world" << endl;

    int answer{ 42 };
    const float goodTemp{ 36.6 };
    int grades[4]{ 11,12,10,9 };
    int mass[2][2]{ {1,2},{3,4} };
    int* ptr{ nullptr };
    int& link{ number };
    Point point{ 10,6 };
    */

}
    

