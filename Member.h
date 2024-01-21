
#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H
class Book;
#include <vector>

#include "Person.h"

class Member : public Person {
private:
    int memberId;
    vector<Book> booksLoaned;

public:
    Member(int _memberId, string name, string address, string email);

    int getMemberId() const;

    void setMemberId(int memberId);

    vector<Book> &getBooksLoaned();

    void setBookBorrowed(Book &book);
};


#endif //LIBRARY_MEMBER_H
