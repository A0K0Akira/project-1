#ifndef LIBRARY_LIBRARIAN_H
#define LIBRARY_LIBRARIAN_H
#include "Person.h"
#include "Member.h"
#include "Book.h"
class Librarian : public Person{
private:
    int staffId;
    int salary;
    vector <Member> members;
    vector <Book> books;
public:
    Librarian(int _staffId,string _name,string _address, string email, int _salary);

    void addMember();

    void issueBook(int memberId, int bookId);

    void returnBook(int memberId, int bookId);

    void displayBorrowedBooks(int memberId);

    void calcFine(int memberId);

    int getStaffId() const;

    void setStaffId(int staffId);

    int getSalary() const;

    void setSalary(int salary);

    Member& getMemberById(int id);
};


#endif //LIBRARY_LIBRARIAN_H
