#include "List.h"
#include "Book.h"
#include <iostream>
using namespace std;

List::List()
{
	this->ds = NULL;
	this->n = 0;
}

List::List(const List & list)
{
	this->n = list.n;
	this->ds = new Book[this->n];
	for(int i = 0; i < this->n; i++) {
		*(this->ds + i) = *(list.ds + i);
	}
}
List::~List(void)
{
	if(n == 0) {
		delete[] ds;
	}
}

ostream & operator << (ostream & o, const List & l){
	for(int i = 0; i < l.n; i++){
		o << l.ds[i] << endl;
	}
	return o;
}

ostream & operator << (ostream & o, const List * l){
	for(int i = 0; i < l->n; i++){
		o << l->ds[i] << endl;
	}
	return o;
}

istream & operator >> (istream & ip, List & l){
	cout << "Nhap N: ";
	ip >> l.n;
	l.ds = new Book[l.n];
	
	for(int i = 0; i < l.n; i++) {
		cout << "Phan tu thu " << i + 1 << " : ";
		ip >> l.ds[i];
	}
	return ip;
}

Book & List::operator[](const int idx){
	if(idx < this->n && idx >= 0){
		return *(this->ds + idx);
	}
	return Book::getNULLBookRef();
}

void List::showAllBooks(){
	for(int i = 0; i < n; i++) {
		cout << *(this->ds + i);
	}
}
void List::addBook(const Book & b, int pos) {
	n += 1;
	Book * books = new Book[n];
	for(int i = 0, j = 0; i < n; i++) {
		if(i == pos) {
			*(books + i) = b; 
		}else {
			*(books + i) = *(this->ds + j++); 
		}
	}
	// chưa xong 
	delete[] this->ds; 
	this->ds = new Book[n];
	for(int i = 0; i < n; i++) {
		*(this->ds + i) = *(books + i);
	}
	delete[] books;
}
void List::addBook(const Book & b) {
	n += 1;
	Book * books = new Book[n];
	for(int i = 0; i < n - 1; i++) {
		*(books + i) = *(this->ds + i); 
	}
	// chưa xong 
	*(books + n - 1) = b; 
	delete[] this->ds;
	this->ds = new Book[n];
	for(int i = 0; i < n; i++) {
		*(this->ds + i) = *(books + i);
	}
	delete[] books;
}

void List::delBook(){
	n = n - 1;
	Book * temp = new Book[n];
	for(int i = 0; i < n; i++) {
		*(temp + i) = *(this->ds + i);
	}
	delete[] this->ds;
	this->ds = new Book[n];
	for(int i = 0; i < n; i++) {
		*(this->ds + i) = *(temp + i);
	}
	delete[] temp;
}
void List::delBook(int pos){
	Book * temp = new Book[n - 1];
	for(int i = 0, j = 0; i < n; i++) {
		if(i != pos){
			*(temp + j++) = *(this->ds + i);
		}
	}
	delete[] this->ds;
	n = n - 1;
	this->ds = new Book[n];
	for(int i = 0; i < n; i++) {
		*(this->ds + i) = *(temp + i);
	}
	delete[] temp;
}

int List::hasBook(string ID){
	for(int i = 0; i < this->n; i++) {
		if(ID.compare((this->ds + i)->getID()) == 0){
			return i;
		}
	}
	return -1;
}

void List::updateBookByID(Book & book){
	string ID = book.getID();
	int idx = hasBook(ID);
	if(idx > -1){
		*(this->ds + idx) = book;
	}
}

int List::getSize(){
	return this->n;
}

void swap(Book &b1, Book &b2){
	Book temp = b1;
	b1 = b2;
	b2 = temp;
}

void List::quickSort(int left, int right){
	int i = left, j = right;
	Book temp = *(this->ds + (i + j) / 2);
	do
    {
		while((this->ds + i)->getID() < temp.getID() && i < right) i++;
		while((this->ds + j)->getID() > temp.getID() && j > left) j--;
		if(i<=j) {
			swap(*(this->ds + i), *(this->ds + j));
			i++;j--;
        }
    }
	while (i<=j);
	if (left<j) quickSort(left,j);
	if (i<right) quickSort(i,right);
}


Book & List::binarySearch(int left, int right, string ID){
	if(right >= left){
		int mid = (left + right) / 2;
		if(ID.compare((ds + mid)->getID()) == 0) return *(ds + mid);
		if(ID.compare((ds + mid)->getID()) < 0){
			return binarySearch(left, mid - 1 , ID);
		}
		return binarySearch(mid + 1 , right, ID);
	}
	return Book::getNULLBookRef();
}