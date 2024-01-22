
#include "Book.h"
#include "Member.h"

Book::Book(int bookId, string bookName,string authorFirstName, string authorLastName):bookId(bookId),bookName(bookName),authorFirstName(authorFirstName),authorLastName(authorLastName) {}

int Book::getBookId() const {
    return bookId;
}

void Book::setBookId(int bookId) {
    this->bookId = bookId;
}

const string &Book::getName() const {
    return bookName;
}

void Book::setName(const string &name) {
    this->bookName = name;
}

const string &Book::getAuthorFirstName() const {
    return authorFirstName;
}

void Book::setAuthorFirstName(const string &authorFirstName) {
    this->authorFirstName = authorFirstName;
}

const string &Book::getAuthorLastName() const {
    return authorLastName;
}

void Book::setAuthorLastName(const string &authorLastName) {
    this->authorLastName = authorLastName;
}

const Date &Book::getDueDate() const {
    return dueDate;
}

void Book::setDueDate(const Date &dueDate) {
    this->dueDate = dueDate;
}

const string &Book::getType() const {
    return type;
}

void Book::setType(const string &type) {
    this->type = type;
}

void Book::borrowBook(Member &_borrower, Date dueDate) {
    this->borrower = &_borrower;
    this->dueDate = dueDate;
}

void Book::returnBook() {
    vector<Book> &books = this->borrower->getBooksLoaned();

    int indexToRemove = -1;
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getBookId() == this->getBookId()) {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove != -1) {
        books.erase(books.begin() + indexToRemove);
    }

}