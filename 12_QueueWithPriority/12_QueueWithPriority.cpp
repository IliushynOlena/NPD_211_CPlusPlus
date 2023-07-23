#include <iostream>
using namespace std;
template<typename T>
struct Element
{
    T value;
    int priority;
};
template<typename T>
class Queue
{
    Element<T>* arr;
    int size;
public:
    Queue() :arr(nullptr), size(0) {}
    ~Queue()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    void Enqueue(Element<T> el)
    {
        int index = 0;
        while (index < size && arr[index].priority < el.priority)
        {
            ++index;//3
        }
        size++;
        Element<T>* temp = new Element<T>[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = el;
        for (int i = index; i < size-1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr)
            delete[]arr;
        arr = temp;
    }
    bool IsEmpty()const
    {
        return size == 0;
    }
    Element<T> Dequeue()
    {
        if (!IsEmpty())
        {
            Element<T> first = arr[0];
            for (int i = 0; i < size-1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element<T>();
    }
    void Print()const
    {
        cout << "----------- Queue ---------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " : " << arr[i].priority << "    ";
        }
        cout << endl;
    }

};


int main()
{
    Queue<string> q;
    Element<string> el = { "A",1 };
    q.Enqueue(el);
    q.Enqueue(Element<string>{ "B",2 });
    q.Enqueue(Element<string>{ "C",3 });
    q.Enqueue(Element<string>{ "G",5 });
    q.Enqueue(Element<string>{ "K",9 });
    q.Print();
    q.Enqueue(Element<string>{ "D",4 });
    q.Print();

    cout << "Element :" <<  q.Dequeue().value<<endl;
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Element :" << q.Dequeue().value << endl;
        q.Print();
    }
  

    
}
