#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
	string idOfBook;
	string nameOfBook;
	int releaseYear;
	int numberOfBook;
	bool hasBook;
	static Book & NOT_FOUND;
public:
	static Book & getNULLBookRef();
	Book(void);
	Book(string, string, int, int);
	~Book(void);
	void show();
	string getID();
	friend ostream & operator<< (ostream &, const Book &);
	friend istream & operator>> (istream &, Book &);
};

