#include "Book.h"

Book::Book()
{
	title = "no titile";
	author = "no author";
	pages = 0;
	year = 0;
	genre = None;
}

void Book::ShowInfo() const
{
	cout << "Title : " << title << endl;
	cout << "Author : " << author << endl;
	cout << "Pages : " << pages << endl;
	cout << "Year : " << year << endl;
	cout << "Genre : " << genre << " ";
	switch (genre)
	{
	case None:cout << "None " << endl;break;
	case Fantasy:cout << "Fantasy " << endl;break;
	case ScienceFiction:cout << "ScienceFiction " << endl;break;
	case Classic:cout << "Classic " << endl;break;
	case Horror:cout << "Horror " << endl;break;
	case Detective:cout << "Detective " << endl;break;
	case Ronam:cout << "Ronam " << endl;break;
	case Comedy:cout << "Comedy " << endl;break;
	case Drama:cout << "Drama " << endl;break;
	}
	cout << "__________________________________________" << endl;
}
