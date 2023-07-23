#include <iostream>
using namespace std;
template<typename T_data>
class List
{
private:
    struct Node
    {
        Node* prev;
        T_data value;
        Node* next;
        Node() :prev(nullptr), value(0), next(nullptr) {}
        Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}
    };
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T_data value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        //newNode->value = value;
        //newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void PrintList()const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }

        //Node* current = head;//int i = 0;
        //while (current != nullptr)//i < 10
        //{
        //    cout << current->value << " ";
        //    current = current->next;//i++;
        //}  
        cout << endl;
    }
    ~List()
    {
        Node* current = head;

        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T_data value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    T_data GetElement(int pos)//3
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i)return current->value;
            current = current->next;
            i++;
        }
        return 0;
    }
    T_data operator[](int pos)//3
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i)return current->value;
            current = current->next;
            i++;
        }
        return 0;
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
};
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
    //int wagonCount;
    List<Vagon> wagons;
public:
    Train(string model)
    {
        this->model = model;
    }
    void AddVagonToHead(Vagon v)
    {
        wagons.AddToHead(v);
    }
};
int main()
{

    List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.PrintList();
    //cout << "Element  3: " << l.GetElement(3) << endl;;
    //cout << "Element  9 : " << l[9] << endl;;

    ///*  cout << "Element : " << l.GetElement(3) << endl;;
    //  cout << "Element : " << l.GetElement(300) << endl;;

    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();

}

