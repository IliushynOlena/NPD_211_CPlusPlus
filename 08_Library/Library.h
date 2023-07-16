#pragma once
#include"Book.h"
/*
* default constructor
* default destructor
* copy constructor
* operator =
*/
class Library
{
private:
	string address;
	Book* books;
	int countBooks;
public:
	Library();
	Library(string address);
	Library(const Library &other)
	{
		this->address = other.address;
		this->countBooks = other.countBooks;
		this->books = new Book[countBooks];
		for (int i = 0; i < countBooks; i++)
		{
			books[i] = other.books[i];
		}
		cout << "Copy constructor" << endl;
	}
	Library& operator =(const Library& other) {
		this->address = other.address;
		this->countBooks = other.countBooks;

		if (books != nullptr)delete[]books;
		this->books = new Book[countBooks];
		for (int i = 0; i < countBooks; i++)
		{
			books[i] = other.books[i];
		}
		cout << "Operator = " << endl;
		return *this;
	}
	Library(Library&& other)
	{
		this->address = other.address;
		this->countBooks = other.countBooks;
		this->books = other.books;
		other.books = nullptr;
		cout << "Move ctor" << endl;
	}
	void Show()const;
	void AddBook(Book b);
	Book GetBookByIndex(int index)const;
	Book operator[](int index)const;
	~Library()
	{
		if (books != nullptr)
			delete[]books;
	}
};

