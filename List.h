#pragma once
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class List 
{
private:
	Book * ds;
	int n;
public:
	List();
	List(const List &);
	~List();
	void addBook(const Book &);
	void addBook(const Book &,int);
	void delBook();
	void delBook(int);
	void showAllBooks();
	void updateBookByID(Book &);
	int hasBook(string);
	Book & operator[] (int);
	friend ostream & operator << (ostream & , const List &);
	friend ostream & operator << (ostream & , const List *);
	friend istream & operator >> (istream & , List &);
	void quickSort(int , int);
	int getSize();
	Book & binarySearch(int, int, string);
};