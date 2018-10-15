#include <iostream>
#include "List.h"
#include "Book.h"
using namespace std;


void menu(List & arr){
	int choose = 0;
	cout << "1. show all books of List"<< endl;
	cout << "2. add book into list at first position" << endl;
	cout << "3. add book into list at K position" << endl;
	cout << "4. add book into list at END_OF_LIST position" << endl;
	cout << "5. delete book from list at first position" << endl;
	cout << "6. delete book from list at K position" << endl;
	cout << "7. delete book from list at END_OF_LIST position" << endl;
	cout << "8. update book by id"<< endl;
	cout << "9. find book by BinarySearch" << endl;
	cout << "10. arrange list by QuickSort" << endl;
	cout << "default: exit!"<<endl;
	cout << "Entering you choose: ";
	cin >> choose;
	Book b;
	switch(choose){
		case 1:
			arr.showAllBooks();
		break;
		case 2:
			arr.addBook(b, 0);
		break;
		case 3:
			arr.addBook(b, 0);
		break;
		case 4:
			arr.addBook(b, arr.getSize());
		break;
		case 5:
			arr.delBook(0);
		break;
		case 6:
			arr.delBook(0);
		break;
		case 7:
			arr.delBook(arr.getSize() - 1);
		break;
		case 8:
			arr.updateBookByID(b);
		break;
		case 9:
			arr.quickSort(0, arr.getSize() - 1);
		break;
		case 10:
			arr.binarySearch(0, arr.getSize() - 1, "0");
		break;
		default: 
			exit(1);
		break;
	}
}

int main(){
	
	List arrayList;
	
	Book b0("0", "Book 0", 1000, 100);
	Book b2("2", "Book 2", 1000, 100);
	Book b1("1", "Book 1", 1000, 100);
	
	arrayList.addBook(b1);
	arrayList.addBook(b0);
	arrayList.addBook(b2);
	arrayList.quickSort(0, arrayList.getSize() - 1);

	Book bs = arrayList.binarySearch(0, arrayList.getSize() - 1, "1212");
	cout << bs;
	cout << arrayList;
	
	Book test;
	cin >> test;

	system("pause");
	return 0;
}