#include "Book.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

Book& Book::NOT_FOUND = Book::Book("NULL", "NULL", 0, 0);

Book& Book::getNULLBookRef(){
	return Book::NOT_FOUND;
}

Book::Book(void)
{
	this->idOfBook = "";
	this->nameOfBook = "";
	this->releaseYear = 0;
	this->numberOfBook = 0;
	this->hasBook = false;
}

Book::Book(string id, string name, int years, int numbers){
	this->idOfBook = id;
	this->nameOfBook = name;
	this->releaseYear = years;
	this->numberOfBook = numbers;
	this->hasBook = (numbers) ? true : false;
}


Book::~Book(void)
{
}

void Book::show(){
	cout << "ID: " << this->idOfBook << "\nNAME: " << this->nameOfBook << "\nYEAR: " << this->releaseYear << "\nNumberOfBook: " << this->numberOfBook << endl;
}

ostream & operator << (ostream & o, const Book & b){
	o << "ID: " << b.idOfBook << "\nNAME: " << b.nameOfBook << "\nYEAR: " << b.releaseYear << "\nNumberOfBook: " << b.numberOfBook <<"\nHasBook: " << b.hasBook << endl;
	return o;
}

istream & operator >> (istream & ip, Book & b){
	string name, id;
	int release, number;
	char a[9];
	cout << "ID BOOK: ";
	ip.getline(a, sizeof(a));
	cout << a;
	cout << "NAME BOOK: ";
	ip.ignore(1);
	getline(ip, name);
	cout<< "RELEASE YEAR: ";
	ip >> release;
	cout<< "NUMBER OF BOOK: ";
	ip >> number;
	Book book(id, name, release, number);
	b = book;
	return ip;
}
string Book::getID(){
	return this->idOfBook;
}