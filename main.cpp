#include <iostream>

#include "Librarian.h"
#include "Book.h"


#define ADD_MEMBER 'a'
#define ISSUE_BOOK 'i'
#define RETURN_BOOK 'r'
#define DISPLAY_BOOKS 'd'
#define QUIT 'q'

char printMenu();

void issueBook(Librarian &librarian);
void returnBook(Librarian &librarian);
void displayAllBooks(Librarian &librarian);
int main() {
    vector<Book> availableBooks;
    Librarian librarian(1,"Admin","191/Mel","librarian@ug.au",10000);
    bool isQuit = false;
    do {
        char user_input = printMenu();

        switch (user_input) {
            case ADD_MEMBER:
                librarian.addMember();
                break;
            case ISSUE_BOOK:
                issueBook(librarian);
                break;
            case RETURN_BOOK:
                returnBook(librarian);
                break;
            case DISPLAY_BOOKS:
                displayAllBooks(librarian);
                break;
            case QUIT:
              isQuit = true;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    } while (!isQuit);


    return 0;
}

char printMenu(){
    char choice;
    cout << "a: Add member\n";
    cout << "i: Issue a book\n";
    cout << "r: Return a book\n";
    cout << "d: Display all books for a member\n";
    cout << "q: Quit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    return choice;

}

bool convertToInteger(string &str, int &result){
    try {
        result = std::stoi(str);
        return true;
    } catch (const std::invalid_argument& e) {
        cout << "Invalid argument: The string does not contain a valid integer." << std::endl;
    } catch (const std::out_of_range& e) {
        cout << "Out of range: The number is too large to fit in an int." << std::endl;
    }
    return false;
}

void issueBook(Librarian &librarian){
    string bookIdStr,memberIdStr;
    int bookId,memberId;
    cout << "Enter BookID : ";
    cin >> bookIdStr;

    cout << "Enter MemberId : ";
    cin >> memberIdStr;

    if (convertToInteger(bookIdStr,bookId) && convertToInteger(memberIdStr,memberId)){
        librarian.issueBook(memberId,bookId);

        return;
    }

}

void returnBook(Librarian &librarian){
    string bookIdStr,memberIdStr;
    int bookId,memberId;
    cout << "Enter BookID : ";
    cin >> bookIdStr;

    cout << "Enter MemberId : ";
    cin >> memberIdStr;
    if (convertToInteger(bookIdStr,bookId) && convertToInteger(memberIdStr,memberId)){
        librarian.returnBook(memberId,bookId);
        return;
    }
}

void displayAllBooks(Librarian &librarian){
    string memberIdStr;
    int memberId;

    cout << "Enter MemberId : ";
    cin >> memberIdStr;

    if (convertToInteger(memberIdStr,memberId)){
        librarian.displayBorrowedBooks(memberId);
        return;
    }
}