#include <iostream>
using namespace std;

class Animal//abstract class
{
    string name;
    int age;
    string place;
    float weight;
public:
    Animal() :name("no name"), age(0), place("no place"), weight(0) {}
    Animal(string n, int a, string p, float w) :name(n),  place(p)
    {
       /* if (w < 0)
            this->weight = 0;
        else
            this->weight = w;*/

        this->weight =  w >= 0 ? w : 0;

       /* if (a < 0)
            this->age = 0;
        else
            this->age = a;*/

        this->age = a >= 0 ? a : 0;    
    }
    void ShowInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void Move()
    {
        cout << "I am moving....." << endl;
    }
    void Eat()
    {
        cout << "I am eating...." << endl;
    }
    virtual void MakeSound() = 0;//pure virtual
   
};

class Lion : public Animal
{
    float runSpeed;
public:
    Lion() :runSpeed(0), Animal() {}
    Lion(string n, int a,string p,float w, float r) :runSpeed(r), Animal(n,a,p,w) {}
    void Move()override
    {
        cout << "I am running with speed : " << runSpeed << " km/h" << endl;
    }
    //virtual void MakeSound() = 0;//pure virtual
    void MakeSound() override
    {
        cout << "Rrrrrrrrrr-rrrrrrrr-rrrrrrrrr" << endl;
    }
};
class Duck: public Animal
{
    float flyHeight;
public:
    Duck() : flyHeight(0), Animal() {}
    Duck(string n, int a, string p, float w, float f) : flyHeight(f), Animal(n,a,p,w) {}
    void Move()override
    {
        cout << "I am swimming and flying up to  : " << flyHeight << " m" << endl;
    }
    void MakeSound() override
    {
        cout << "Kra-kra-kra-kra" << endl;
    }    
};

class Reptile : public Animal // abstract class
{
    float swimDeep;
public:
    Reptile() :swimDeep(0), Animal() {}
    Reptile(string n, int a, string p, float w, float s) :swimDeep(s), Animal(n,a,p,w) {}
    void Move()override
    {
        cout << "I am crowling and  swimming  up to  : " << swimDeep << " m" << endl;
    }
};
class Frog: public Reptile
{
public:
    Frog() : Reptile() {}
    Frog(string n, int a, string p, float w, float s) : Reptile(n,a,p,w,s) {}
   
    void MakeSound() override
    {
        cout << "Kva-kva-kva-kva" << endl;
    }
};
void RollCall(Animal &animal)
{
    animal.MakeSound();
    animal.Move();
}

int main()
{
    Frog frog("Craze Frog", 1, "Boloto", 1, 5);
    Duck duck("Duffy",5,"America",7,1000 );
    duck.Eat();
    duck.Move();
    duck.MakeSound();
    duck.ShowInfo();
    cout << endl;
    Lion lion("King Lion",15,"Africa",150,80);
   
    lion.Eat();
    lion.Move();
    lion.MakeSound();
    lion.ShowInfo();
    cout << "----------------------------" << endl;
    RollCall(duck);
    RollCall(lion);
    RollCall(frog);


    Animal* zoo[2]{ &lion, &duck };
    
  /*  Animal animal;
    animal.Eat();
    animal.Move();
    animal.MakeSound();*/
    
}

