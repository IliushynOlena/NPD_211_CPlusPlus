#include <iostream>
using namespace std;

class Person//abstract class
{
protected:
    string name;   
public:
    Person() :name("no name"){}
    Person(string name) : name(name) {}
   
    virtual void Print()const
    {
        cout << "Student name : " << name << endl;
        cout << endl;
    }
    virtual ~Person() = 0 {};// pure virtual destructor {}
   
};
class Aspirant : public Person
{
    string* subjects;
    int countSub;
public:
    Aspirant(string n, initializer_list<string> list) : Person(n)
    {
        //theme1, theme2, theme3
        this->countSub = list.size();
        subjects = new string[countSub];
        int i = 0;
        for (string sub : list)
        {
            subjects[i] = sub;
            i++;
        }
    }
    void Print()const override
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSub; i++)
        {
            cout << subjects[i] << " ";
        }
        cout << endl;
    }
    ~Aspirant()
    {
        cout << "Destructor Aspirant....." << name << endl;
        if (subjects != nullptr)
            delete[]subjects;
    }

};

int main()
{
    srand(time(0));
    Aspirant asp("Oleg", { "World war" ,"Independency day Of America", "Dovbush" });
    asp.Print();
    Person* group[2]
    {
        //new Person("Vasia"),
        new Aspirant("Ivanka",  { "World war" ,"Independency day Of America", "Dovbush"}),
        new Aspirant("Oksana",  { "Time" ,"England"})
    };
    for (int i = 0; i < 2; i++)
    {
        group[i]->Print();
        cout << endl;
        delete group[i];
    }

    //MyClass m;//default constructor
    //m.setA(100);
    //m.Print();
    //MyClass m2(m);//copy constructor
    //m2.Print();
    //MyClass m3 = m;//operator =
    //m3.Print();
    //m2 = m;

}

