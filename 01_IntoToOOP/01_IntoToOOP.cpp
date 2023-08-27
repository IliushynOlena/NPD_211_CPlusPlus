#include <iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
/*
struct Player
{
    string name;
    short age;
    int games;
    int goals;
};

void PrintPlayer(Player &pl)
{
    cout << "Name : " << pl.name << endl;
    cout << "Age : " << pl.age << endl;
    cout << "Games : " << pl.games << endl;
    cout << "Goals : " << pl.goals << endl;
}

void InitPlayer(Player& pl)
{
    cout << "Name : ";
    cin >> pl.name;
    cout << "Age : ";
    cin >> pl.age;
    pl.games = 0;
    pl.goals = 0;
}
void AddGameToPlayer(Player& pl, int goals = 0)
{
    ++pl.games;
    pl.goals += goals;
}
*/

class Player
{
private:
    string name;
    short age;
    int games;
    int goals;
    bool IsValidGoals(int goals) { return goals >= 0; }
public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void Initialize()
    {
        name = "no name";
        age = 0;
        games = 0;
        goals = 0;
    }
    void InitPlayerFromKeyboard()
    {
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
    }
    
    void AddGameToPlayer(int goals = 0)
    {
        ++games;
        if(IsValidGoals(goals))
            this->goals += goals;
    }
};


//class Student
//{
//private:
//    //data members -змінні-члени класу
//    string name;
//    int marks[3];
//public:
//    //member function - методи
//    double getAverage()
//    {
//        double sum = 0;
//        for (size_t i = 0; i < 3; i++)
//        {
//            sum += marks[i];
//        }
//        return sum / 3;
//    }
//    void setName(string name)
//    {
//        this->name = name;
//    }
//    string getName()
//    {
//        return name;
//    }
//    void setMark(int mark, int index)
//    {
//        if (mark < 1 or mark > 12)
//            mark = 0;
//        marks[index] = mark;
//    }
//    int getMark(int index)
//    {
//        return marks[index];
//    }
//
//};

class Person
{
private:
    //data members -змінні-члени класу
    string name;
    string surname;
    int age;
    int *marks;
    int countMark;
    float averageMark;
public:
    //ctor + TAB
    Person()
    {
        cout << "Default constructor  " <<name << endl;
        name = "none";
        age = 0;
        marks = nullptr;
        countMark = 0;
        averageMark = 0;
    }
    Person(string name)
    {
        cout << "Parametrized  constructor "<<name << endl;
        this->name = name;
        age = 0;
        marks = nullptr;
        countMark = 0;
        averageMark = 0;
    }
    Person(string name, int age)
    {
        cout << "Parametrized  constructor " << name << endl;
        this->name = name;
        this->age = age;
        marks = nullptr;
        countMark = 0;
        averageMark = 0;
    }
    //member function - методи
    void setAverage()
    {
        float sum = 0;
        for (size_t i = 0; i <countMark; i++)
        {
            sum += marks[i];
        }
        averageMark =  sum / countMark;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setMark(int mark, int index)
    {
        if (mark < 1 or mark > 12)
            mark = 0;
        marks[index] = mark;
    }
    int getMark(int index)
    {
        return marks[index];
    }
    void Print()
    {
        gotoxy(10, 10); cout << "Name : " << name << endl;
        gotoxy(10, 11); cout << "Marks : ";
        for (size_t i = 0; i < countMark; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        gotoxy(10, 12); cout << "Average : " << averageMark << endl;
    }
    void AddMark(int mark)
    {
        //int* marks  = nullptr;
        //int countMark = 0;
        countMark++;//1
        int* temp = new int[countMark];
        for (int i = 0; i < countMark-1; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMark - 1] = mark;
        if (marks != nullptr)
            delete[]marks;
        marks = temp; 
        setAverage();
    }

    //~ + TAB
    ~Person()
    {
        cout << "Destructor "<<name << endl;
        if (marks != nullptr)
            delete[]marks;
    }

};
int main()
{
    
    Person st;//default
    st.Print();


    Person st2("Olena");
    st2.Print();

    Person st3("Petro", 12);
    st3.AddMark(8);
    st3.AddMark(9);
    st3.AddMark(12);
    st3.AddMark(3);
    st3.AddMark(7);
    st3.Print();

    /*
    int a = 5;
    Student st;//object
    st.setName("Anatoliy");
    st.setMark(12,0);
    st.setMark(8,1);
    st.setMark(9,2);   
    cout << "Name : " << st.getName() << " Marks : " << st.getMark(0) << endl;
    cout << "Average mark :" << st.getAverage() << endl;
    */
    /*
    Player pl;
    pl.Initialize();
    pl.InitPlayerFromKeyboard();
    pl.AddGameToPlayer(2);
    pl.AddGameToPlayer();
    pl.AddGameToPlayer(5);
    pl.PrintPlayer();
    */
    /*
    Player pl;
    InitPlayer(pl);
    PrintPlayer(pl);

    AddGameToPlayer(pl);
    AddGameToPlayer(pl, 3);
    AddGameToPlayer(pl, 2);
    PrintPlayer(pl);
   */
    
}

