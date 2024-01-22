#include <iostream>
#include "Librarian.h"
#include "Date.h"
#include <limits>
#include <fstream>
#include <sstream>

void loadFromFile(vector<Book> &availableBooks){
    string filename;
    ifstream file;
    string line;


    while (true) {
        cout << "Enter file name: ";
        cin >> filename;

        file.open(filename);
        if (!file) {
            cout << "Error cannot read in file!\n" ;
            file.clear();
        } else {
            break;
        }
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string name,authorFirstname,authorLastname, type;
        int bookId,pageCount;

        ss >> bookId;
        ss.ignore();

        getline(ss, name, ',');
        ss >> pageCount;
        ss.ignore();

        getline(ss, authorFirstname, ',');
        getline(ss, authorLastname, ',');
        getline(ss, type);
        Book book(bookId,name,authorFirstname,authorLastname);
        book.setType(type);
        availableBooks.push_back(book);
    }

    file.close();
}

Librarian::Librarian(int _staffId, string _name, string _address, string email, int _salary) : Person(
        _name, _address, email), staffId(_staffId), salary(_salary) {
    loadFromFile(books);
}


void Librarian::addMember() {
    int memberId;
    string name, address, email;
    cout << "Enter Member Id (integer only): ";
    while (!(cin >> memberId)) {
        cerr << "Invalid input. Please enter an integer for Member Id: ";
        cin.clear(); // Clears the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter email: ";
    getline(cin, email);

    for (auto &member: members) {
        if (member.getMemberId() == memberId) {
            cout << "ID already exists!\n";
            return;
        }
    }

    Member newMember(memberId, name, address, email);
    cout << "Member Created" << endl;
    cout << "ID      : " << newMember.getMemberId()<< endl;
    cout << "Name    : " << newMember.getName() << endl;
    cout << "Address : " << newMember.getAddress() << endl;
    cout << "Email   : " << newMember.getEmail() << endl;

    members.push_back(newMember);
}

int Librarian::getStaffId() const {
    return staffId;
}

void Librarian::setStaffId(int staffId) {
    this->staffId = staffId;
}

int Librarian::getSalary() const {
    return salary;
}

void Librarian::setSalary(int salary) {
    this->salary = salary;
}


void Librarian::issueBook(int memberId, int bookId) {
    bool isFoundMember = false;
    bool isFoundBook = false;

    for (auto &member: members) {
        vector<Book> booksLoaned = member.getBooksLoaned();
        for (auto &book: booksLoaned) {
            if (book.getBookId() == bookId){
                cout << "Book was borrowed by " << member.getMemberId() << " Name : " << member.getName() << endl;
                return;
            }
        }
    }

    for (auto &member: members) {
        if (member.getMemberId() == memberId){
            isFoundMember = true;
            for (auto & book : books) {
                if (book.getBookId() == bookId){

                    Date dueDate;
                    dueDate.addDays(3);
                    book.borrowBook(member,dueDate);
                    member.setBookBorrowed(book);
                    isFoundBook = true;
                    cout << "Book Issued to User\n\n";
                }
            }
        }
    }
    if (!isFoundMember){
        cout << "Member not found!\n";
        return;
    }
    else if(!isFoundBook){
        cout << "Book not available!\n";
        return;
    }

}

void Librarian::calcFine(int memberId) {
    int total = 0;
    for (auto &member: members) {
        if (member.getMemberId() == memberId){
            const vector<Book> &booksBorrowed = member.getBooksLoaned();

            for (auto &book: booksBorrowed) {
                Date dueDate;
                int diff = dueDate.getDifference(book.getDueDate());
                if (diff > 0){
                    total = total + abs(diff) * 1;
                }
            }
        }
    }
    if (total != 0) {
        cout << "Remaining fine balance for borrowed books for today is £" << total << endl;
    }
}

void Librarian::returnBook(int memberId, int bookId) {
    bool isFoundMember = false;
    bool isFoundBook = false;
    for (auto &member: members) {
        if (member.getMemberId() == memberId){
            isFoundMember = true;
            for (auto & book : member.getBooksLoaned()) {
                if (book.getBookId() == bookId){
                    isFoundBook = true;
                    Date dueDate;
                    int difference = dueDate.getDifference(book.getDueDate());
                    if (difference > 0){
                        cout << "Fine value for this book: £" << abs(difference) << endl;
                    }
                    book.returnBook();
                    calcFine(member.getMemberId());
                    cout << "Book returned" << endl;
                }
            }
        }
    }
    if (!isFoundMember){
        cout << "Member not found!\n";
        return;
    }
    else if(!isFoundBook){
        cout << "Book not found!\n";
        return;
    }
}


void Librarian::displayBorrowedBooks(int memberId) {
    bool isFoundMember = false;
    for (auto &member: members) {
        if (member.getMemberId() == memberId){
            isFoundMember = true;
            for (auto & book : member.getBooksLoaned()) {
                cout << "ID                :" << book.getBookId() << endl;
                cout << "Name              :" << book.getName() << endl;
                cout << "Author First Name :" << book.getAuthorFirstName() << endl;
                cout << "Author L ast Name : " << book.getAuthorLastName() << endl;
                cout << "Type              : " << book.getType() << endl << endl;
            }
        }
    }
    if (!isFoundMember){
        cout << "Member not found!\n";
        return;
    }

}