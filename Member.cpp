#include "Member.h"
#include "book.h"

Member::Member(int _memberId, string name, string address, string email): Person(name,address,email),memberId(_memberId){}

int Member::getMemberId() const {
    return memberId;
}

void Member::setMemberId(int memberId) {
    Member::memberId = memberId;
}

vector<Book> &Member::getBooksLoaned(){
    return booksLoaned;
}

void Member::setBookBorrowed(Book &book) {
    booksLoaned.push_back(book);
}
