#include "Library.h"

 Library::Library()
{
	address = "none";
	books = nullptr;
	countBooks = 0;
}

 Library::Library(string address) :address(address)
{
	books = nullptr;
	countBooks = 0;
}
 void Library::Show() const
{
	cout << "Address : " << address << endl;
	cout << endl;
	for (int i = 0; i < countBooks; i++)
	{
		books[i].ShowInfo();
	}
}

void Library::AddBook(Book b)
{
	Book* temp = new Book[countBooks + 1];
	for (int i = 0; i < countBooks; i++)
	{
		temp[i] = books[i];
	}
	temp[countBooks] = b;
	if (books != nullptr)
		delete[]books;
	books = temp;
	countBooks++;
}

Book Library::GetBookByIndex(int index) const
{
	if (index >= 0 && index < countBooks)
		return books[index];
	return Book();
}

Book Library::operator[](int index) const
{
	if (index >= 0 && index < countBooks)
		return books[index];
	return Book();
}
