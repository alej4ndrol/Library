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

class Library {
	vector<Book> books_arr;

public:
	Library(vector<Book> books_arr) {
		this->books_arr = books_arr;
	}
	void add_book(Book book) {
		books_arr.push_back(book);
	}

	void erase_book(int index) {
		if (index == -1)
			cout << "There is no such  book." << endl;
		else
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

	void print_book_list() {
		cout << "Book list: " << endl;
		for (size_t i = 0; i < books_arr.size(); i++)
		{
			cout << i << ". " << books_arr[i].get_book_name() << endl;
		}
		cout << endl;
	}
};

class Visitor {
public:

	void take_book(Library* library, string book_name) {
		cout << "You took the book: " << "'" << book_name << "'" << endl;
		library->erase_book(library->find_book(book_name));
		library->print_book_list();
	}

	void return_book(Library* library, string book_name) {
		library->add_book(book_name);
		cout << "You returned the book: " << "'" << book_name << "'" << endl;
		library->print_book_list();
	}
};

int main() {

	Visitor Alex;
	Book book1("book_1");
	Book book2("book_2");
	Book book3("book_3");
	Book book4("book_4");
	Library library({ book1, book2, book3, book4 });
	Alex.take_book(&library, "book_1");
	Alex.return_book(&library, "book_6");
	Alex.take_book(&library, "book_7");
	Alex.take_book(&library, "book_4");
	Alex.return_book(&library, "book_1");

	return 0;
}
