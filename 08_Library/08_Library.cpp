#include"Book.h"
#include"Library.h"

Library TestLibrary(Library& lib)//copy ctor /// 30000
{
    Library temp;//default constructor
    //some code
    temp = lib;//operator =
    return temp;
}

int main()
{
    

	Book book;
    Book book1("C++ for Begginers", "Stiven Prata",  1500, 2000, ScienceFiction);
  /*  Book book2("Harry Potter", "J.K.Rowling",  800, 1997, Fantasy);
    Book book3("Sherlock Holmes", "Arthur Conan Doyle", 2000, 1887, Genre::Detective);
    Book book4("Java for kids", "Morgan Nick",  408, 2015, ScienceFiction);
    Book book5("Mowgli", "Pantera", 500, 1893, Genre::Fantasy);
    Book book6("Financier", "Dreiser Theodore",   377, 1911, Genre::ScienceFiction);

    book1.ShowInfo();*/
#pragma region Library
    Library lib("Soborna 16");
    lib.AddBook(book1);
    lib.AddBook(Book("Harry Potter", "J.K.Rowling", 800, 1997, Fantasy));
    lib.AddBook(Book("Sherlock Holmes", "Arthur Conan Doyle", 2000, 1887, Genre::Detective));
    lib.AddBook(Book("Java for kids", "Morgan Nick", 408, 2015, ScienceFiction));
    lib.AddBook(Book("Mowgli", "Pantera", 500, 1893, Genre::Fantasy));

    lib.Show();
    cout << "*********************************" << endl;
    Book b = lib.GetBookByIndex(2);
    b.ShowInfo();
    b = lib[100];
    b.ShowInfo();
    cout << "*********************************" << endl;

   

#pragma endregion

    Library newLib(lib);//copy ctor
    //newLib = lib;
    newLib.Show();

    int t = 4, m = 5;
    int g = t = m = 0;
    Library lib3;
    lib = lib3 = newLib;

    TestLibrary(lib);

  


}
