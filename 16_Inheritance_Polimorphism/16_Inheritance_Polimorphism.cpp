#include <iostream>
#include <windows.h> 
using namespace std;

class Car
{
protected:
	string model;
	int power;
	int maxSpeed;
	int year;
public:
	Car() : model("none"), power(0), maxSpeed(0), year(0) {}
	Car(string m, int p, int y) : model(m), power(p), maxSpeed(0), year(y) {}
	virtual void Drive()const//virtual method
	{
		cout << "I am a Car. I can drive with speed : " << maxSpeed << " km/h" << endl;
	}
	void SetSpeed(int speed)
	{
		if (speed >= 0)
			this->maxSpeed = speed;
	}
	virtual void Print()const
	{
		cout << "Model : " << model << endl;
		cout << "Power : " << power << endl;
		cout << "Max Speed : " << maxSpeed << endl;
		cout << "Year : " << year << endl;
		cout << endl;
	}
};
class PoliceCar : public Car
{
	int soundVolume;
public:
	PoliceCar() :soundVolume(0), Car() {}
	PoliceCar(string m, int p, int y, int s) :soundVolume(s), Car(m,p,y) {}
	void Drive()const override
	{
		cout << "I am a Police Car. I can drive with speed : " << maxSpeed << " km/h" << endl;
	}
	void Print() const override
	{
		cout << "---------- Police car-------------" << endl;
		Car::Print();
		cout << "Sound volume " << soundVolume << endl;
		cout << endl;
	}
	void BeepBeep()
	{
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(262, 300); Sleep(300);
        Beep(196, 300); Sleep(300);
        Beep(164, 300); Sleep(300);
        Beep(220, 300); Sleep(100);
        Beep(246, 100); Sleep(300);


	}
	
};
class SportCar: public Car
{
	int turbo;
public:
	SportCar() : turbo(0), Car() {}
	SportCar(string m, int p, int y, int t) : turbo(t), Car(m,p,y) {}
	void Drive()const override
	{
		cout << "I am a Sport Car. I can drive with speed : " << maxSpeed << " km/h" << endl;
	}
	void Print()const override
	{
		cout << "---------- Sport Car-------------" << endl;
		Car::Print();
		cout << "Nitro speed " << turbo << "km/ h "<< endl;
		cout << endl;
	}
	void Nitro()
	{
		cout << " Enable nitro speed " << endl;
		maxSpeed += turbo;
		cout << "------------------> " << maxSpeed << "km / h" << endl;
	}

};

void TestDrive(Car& car)
{
	car.SetSpeed(60);
	car.Drive();
	car.Print();

}

int main()
{

	Car* carSalon[3]{
		new Car("Audi", 300, 2021),
		new PoliceCar("Ford",500,2018,500),
		new SportCar("Ferari", 1000, 1994, 50)
	};
	for (int i = 0; i < 3; i++)
	{
		carSalon[i]->SetSpeed(70);
		carSalon[i]->Drive();
	}
	for (int i = 0; i < 3; i++)
	{
		delete carSalon[i];
	}


	SportCar sport("Ferari", 1000, 1994, 50);
	sport.SetSpeed(400);
	sport.Drive();
	sport.Nitro();
	sport.Print();
	
	Car simpleCar("Audi", 300, 2021);
	simpleCar.SetSpeed(320);
	simpleCar.Drive();
	simpleCar.Print();

	PoliceCar police("Ford",500,2018,500);
	police.SetSpeed(330);
	police.Drive();
	police.Print();
	//police.BeepBeep();
	cout << endl;
	TestDrive(simpleCar);
	TestDrive(police);
	TestDrive(sport);
	
   
}

