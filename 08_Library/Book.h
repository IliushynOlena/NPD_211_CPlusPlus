#pragma once
#include <iostream>
using namespace std;

enum Genre
{
	None,Fantasy,ScienceFiction, Classic, Horror, Detective, Ronam, Comedy, Drama
};
class Book
{
private:
	string title;
	string author;
	int pages;
	int year;
	Genre genre;
public:
	Book();
	Book(string t, string a, int p, int y, Genre g) :title(t), author(a), pages(p), year(y), genre(g) {}
	void ShowInfo()const;
	


};

