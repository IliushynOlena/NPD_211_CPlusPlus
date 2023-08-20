#include <iostream>
using namespace std;

class Enemy
{
protected:
    string name;
    int health;
    float power;
    static const int maxHealth = 100;
public:
    Enemy() :name("no name"), health(maxHealth), power(0) {}
    Enemy(string n, float p) :name(n), health(maxHealth), power(p) {}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << "% "<< endl;
        cout << "Power : " << power << endl;
    }
    void DecreaseHealth(int value)//0 - 15
    {
        if (health - value < 0)
            health = 0;
        else
            health -= value;
    }
    bool IsAlive()const
    {
        return health > 0;
    }
};

//Inheritance
//class Child : [spetificator] Paternt
//[spetificator]  - private, public, protected
class Dragon : public Enemy
{
    float fire;
public:
    Dragon() :fire(0), Enemy() {}
    //{
       // name = "no name"; health = maxHealth; power = 0;
    //}
    Dragon(string name, float power, float fire ) :fire(fire), Enemy(name, power) {}
    void Fight(int damage)
    {
        cout << "Getting damage : " << damage << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after getting damage " << health << " % " << endl;
    }
    float Attack()
    {
        cout << "Attacking with : " << power << " power !!!" << endl;
        return power;
    }
    void Print()
    {
        cout << "------------ Dragon ---------------" << endl;
        Enemy::Print();
        cout << "Fire : " << fire << endl;
    }
};
class Monster : public Enemy
{
    float runSpeed;
public:
    Monster() :runSpeed(0), Enemy() {}
    Monster(string name, float p,float r) :runSpeed(r), Enemy(name, p) {}
    void Run()
    {
        cout << "Running with " << runSpeed << " km/h" << endl;
    }

};

int main()
{
    Monster m("Zombi",3,150);
    m.Print();
    m.Run();
     
    Dragon dragon("Igor",5,1);
    Dragon boss("Bill", 6, 2);
    int i = 0;

    do
    {
        cout << "-------- Round " << ++i << "------------" << endl;
        dragon.Fight(boss.Attack());
        boss.Fight(dragon.Attack());

        dragon.Print();
        boss.Print();
        i++;
        cout << endl;

    } while (dragon.IsAlive()&& boss.IsAlive());

     
   
}

