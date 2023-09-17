#include <iostream>
#include <list>
using namespace std;

void ShowLists(list<int> l1, list<int> l2)
{
    list<int>::iterator it;
    cout << "List 1: ";
    for (it = l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "List 2: ";
    for ( auto it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
}
struct Book
{
    string name;
    string author;
    int pages;
};

bool CompareBookByName(const Book& b1, const Book& b2)
{
    return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
    return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2)
{
    return b1.pages < b2.pages;
}
int main()
{

    list<Book> library;

    library.assign(
        {
            Book{"Night","Gogol",786},
            Book{"Maria","Kotliarevskuy",200},
            Book{"Harry Potter","Royling",600}
        });
    cout << "------------ Original list ---------------" << endl;
    for (Book b : library)
    {
        cout << b.name << " " << b.author << " " << b.pages << endl;
    }

    cout << "------------ Sorted list by name ---------------" << endl;
    //cout << CompareBookByName << endl;
    library.sort(CompareBookByName);
    for (Book b : library)
    {
        cout << b.name << " " << b.author << " " << b.pages << endl;
    }
    cout << "------------ Sorted list by author ---------------" << endl;
    //cout << CompareBookByName << endl;
    library.sort(CompareBookByAuthor);
    for (Book b : library)
    {
        cout << b.name << " " << b.author << " " << b.pages << endl;
    }
    cout << "------------ Sorted list by pages ---------------" << endl;
    //cout << CompareBookByName << endl;
    library.sort(CompareBookByPages);
    for (Book b : library)
    {
        cout << b.name << " " << b.author << " " << b.pages << endl;
    }
    /*
    list<int> l1, l2;//default     head = nullptr;tail = nullptr;

    for (int i = 0; i < 6; i++)
    {
        l1.push_back(i); 
        l2.push_front(i);
    }
    ShowLists(l1, l2);

    l1.assign({ 10,11,12 });
    ShowLists(l1, l2);

    l1.erase(l1.begin());
    list<int>::iterator i = l1.end();
    i--;
    l1.erase(i);
    ShowLists(l1, l2);

    l1.push_back(2);
    l1.push_back(2);
    l1.push_front(2);
    l1.push_front(2);
    ShowLists(l1, l2);

    l1.remove(2);
    ShowLists(l1, l2);

    l1.insert(l1.begin(), 99);
    ShowLists(l1, l2);
    l1.insert(l1.end(), { 111,112,113,114,115 });
    ShowLists(l1, l2);
    list<int>::iterator it = l2.begin();
    it++;
    it++;
    l1.insert(l1.begin(),it, l2.end());
    ShowLists(l1, l2);
    l1.insert(l1.end(), 5, 88);
    ShowLists(l1, l2);
    cout << "Size : " << l1.size() << endl;
    //cout << "Size : " << l1.capacity() << endl;
    l1.resize(30,8);
    ShowLists(l1, l2);

    l1.splice(l1.end(), l2, l2.begin());
    ShowLists(l1, l2);

    l1.reverse();
    ShowLists(l1, l2);

    l1.sort();
    l2.sort();
    ShowLists(l1, l2);

    l1.merge(l2);
    ShowLists(l1, l2);

    l1.unique();
    ShowLists(l1, l2);

    l1.swap(l2);
    ShowLists(l1, l2);
    */
    
    
}

