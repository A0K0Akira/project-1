#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
class Member;

#include "Date.h"
#include <string>

using namespace std;
class Book {
private:
    int bookId;
    string bookName;
    string authorFirstName;
    string authorLastName;
    string type;
    Date dueDate;
    Member*  borrower;
public:
    Book(int bookId, string bookName,string authorFirstName, string authorLastName);

    int getBookId() const;

    void setBookId(int bookId);

    const string &getName() const;

    void setName(const string &name);

    const string &getAuthorFirstName() const;

    void setAuthorFirstName(const string &authorFirstName);

    const string &getAuthorLastName() const;

    void setAuthorLastName(const string &authorLastName);

    const Date &getDueDate() const;

    void setDueDate(const Date &dueDate);

    const string &getType() const;

    void setType(const string &type);

    void returnBook();

    void borrowBook(Member& borrower, Date dueDate);
};


#endif //LIBRARY_BOOK_H
