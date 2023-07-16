#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    int* arr;
    int maxSize;
    int topIndex;
public:
    Queue() = delete;
    Queue(int maxSize) 
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        topIndex = 0;
    }
    ~Queue()
    {
        delete[]arr;
    }
    bool IsEmpty()const
    {
        return topIndex == 0;
    }
    bool IsFull()const
    {
        return topIndex == maxSize;
    }
    void Enqueue(int element)
    {
        if (!IsFull())
            arr[topIndex++] = element;
    }
    int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 1; i < topIndex; i++)
            {
                arr[i - 1] = arr[i];
            }
            //simple queue
            //topIndex--;
            arr[topIndex - 1] = first;

            return first;        
        }
    }
    int GetCount()const
    {
        return topIndex;
    }
    void Clear()
    {
        topIndex = 0;
    }
    void Print()const
    {
        cout << "------------ Queue -------------" << endl;
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int Peek()const
    {
        if (!IsEmpty())return arr[0];
    }
};

int main()
{
    Queue q(25);

    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 30);
    }
    q.Print();

    cout << "Element : " << q.Dequeue() << endl;
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Element : " << q.Dequeue() << endl;
        q.Print();
        _getch();
    }


    
}

