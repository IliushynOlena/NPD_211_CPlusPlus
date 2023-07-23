#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node() :value(0), next(nullptr) {}
    Node(int value, Node* next) :value(value), next(next) {}
};

class List
{
private:
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head);
        //newNode->value = value;
        //newNode->next = head;
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
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }      
    }
    int GetElement(int pos)//3
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
    int operator[](int pos)//3
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
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }      
    }
};

int main()
{

    List l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.PrintList();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.PrintList();
    cout << "Element  3: " << l.GetElement(3) << endl;;
    cout << "Element  9 : " << l[9] << endl;;

  /*  cout << "Element : " << l.GetElement(3) << endl;;
    cout << "Element : " << l.GetElement(300) << endl;;

    l.DeleteFromTail();
    l.DeleteFromTail();*/
    l.DeleteFromTail();
    l.PrintList();
    
}

