#include <iostream>

using namespace std;
//    Для масиву вагонів створити окрему структуру
//    В наступними полями :
//    struct Vagon
//    номер вагону
//    кількість місць
//    кількість пасажирів
//    class Train
//    Створити клас Потяг.У класі оголосити поля(змінні члени класу) :
//    модель
//    кількість вагонів
//    вказівник на масив вагонів(динамічний).Vagon vagon; *
//    В класі потяг оголосити дефолтний конструктор
//    і перезавантажений конструктор.
//    Реалізувати метод Show()
//    Реалізувати метод додавання вагону до динамічного масиву
//    Реалізувати метод - додати 1 пасажира у вагон
//    Реалізувати конструктор копіювання
struct Vagon
{
    int number;
    int seatCount;
    int passengerCount;
    void print()
    {
        cout << "Number:" << number << endl;
        cout << "SeatsCount:" << seatCount << endl;
        cout << "PassengersCount:" << passengerCount << endl;
    }
};

class Train
{
private:
    string model;
    int wagonCount;
    Vagon* wagons;
public:
    Train()
    {
        model = "";
        wagonCount = 0;
        wagons = nullptr;
    }

    Train(string trainModel)
    {
        model = trainModel;
        wagonCount = 0;
        wagons = nullptr;
    }

    Train(const Train& otherTrain)
    {
        model = otherTrain.model;
        wagonCount = otherTrain.wagonCount;

        wagons = new Vagon[wagonCount];
        for (int i = 0; i < wagonCount; i++)
        {
            wagons[i] = otherTrain.wagons[i];
        }
    }
    void Show()
    {
        cout << "Model:" << model << endl;
        cout << "CountofVagons:" << wagonCount << endl;
        for (int i = 0; i < wagonCount; i++)
        {
            wagons[i].print();
            cout << endl;
        }
    }
    void AddVagon(Vagon value)
    {
        Vagon* new_arr = new Vagon[wagonCount + 1];
        for (size_t i = 0; i < wagonCount; ++i)
        {
            new_arr[i] = wagons[i];
        }
        new_arr[wagonCount] = value;
        if (wagons != nullptr)
            delete[] wagons;
        wagons = new_arr;
        ++wagonCount;
    }
    void Addonepassenger(int number)
    {
        for (int i = 0; i < wagonCount; i++)
        {
            if (wagons[i].number == number)
            {
                wagons[i].passengerCount++;
            }
        }
    }
    Train operator+(const Train& other)
    {
        Train newTrain(*this);//constructor copy
        for (int i = 0; i < other.wagonCount; i++)
        {
            newTrain.AddVagon(other.wagons[i]);
        }
        return newTrain;
    }
};

void main()
{
    Train train("Tomas");
    train.AddVagon(Vagon{ 1,15,3 });
    train.AddVagon(Vagon{ 2,23,4 });
    train.AddVagon(Vagon{ 3,21,5 });
    train.AddVagon(Vagon{ 4,11,6 });
    train.Show();
    Train NewTrain(train);//copy ctor
    NewTrain.Addonepassenger(1);
    NewTrain.Addonepassenger(2);
    NewTrain.Addonepassenger(3);
    NewTrain.Addonepassenger(4);
    NewTrain.Show();
    cout << "-----------------------" << endl;
    Train superTrain = train + NewTrain;
    superTrain.Show();
}
