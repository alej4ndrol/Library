//Предметная область : Библиотека
//Информационные объекты : Библиотека, Библиотекарь, Книги, Авторы, Посетитель
//
//У книги может быть только один автор.
//
//Посетитель посещает библиотеку с целью найти книгу по имени автора И / ИЛИ по названию книги.
//
//Необходимо реализовать данный функционал, придерживаясь принципов DRY, KISS, YAGNI и Single Responsibility Principle

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library {
	vector<Book> books_arr;

protected:
	void add_book(Book book) {
		books_arr.push_back(book);
	}

	void erase_book(int index) {
		books_arr.erase(books_arr.begin() + index);
	}

	int find_book(string book_name) {
		int book_num = -1;
		for (size_t i = 0; i < books_arr.size(); i++)
		{
			if (books_arr[i].get_book_name() == book_name) {
				book_num = i;
			}
		}
		return book_num;
	}
public:
	Library(vector<Book> books_arr){
		this->books_arr = books_arr;
	}
};

class Book {
	string book_name;
public:
	Book(string book_name) {
		this->book_name = book_name;
	};

	string get_book_name() {
		return book_name;
	}


};

class Visitor : protected Library {
public:

	void take_book(string book_name) {
		Library::erase_book(find_book(book_name));
	}

	void return_book(string book_name) {
		Library::add_book(book_name);
	}
};



int main() {

	Visitor Alex;
	Book book1("book_1");
	Book book2("book_2");
	Book book3("book_3");
	Book book4("book_4");
	Library library({book1, book2, book2, book4 });
	//library.add_book(book1);


	return 0;
}