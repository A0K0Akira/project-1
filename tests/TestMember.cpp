#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "Member.h"
#include "Book.h"

TEST_CASE("Member Creation and Property Tests", "[Member]") {
    Member member(123, "John Doe", "123 Street", "johndoe@example.com");

    SECTION("Test Member Properties") {
        REQUIRE(member.getMemberId() == 123);
        REQUIRE(member.getName() == "John Doe");

        member.setMemberId(456);
        REQUIRE(member.getMemberId() == 456);
    }
}

TEST_CASE("Return Books", "[Member]") {
    Member member(123, "John Doe", "123 Street", "johndoe@example.com");
    Book book1(1, "Book One", "Author1", "Author1Last");
    Book book2(2, "Book Two", "Author2", "Author2Last");


    SECTION("Returns books and Due dates"){
        member.setBookBorrowed(book1);
        member.setBookBorrowed(book2);
        Date dueDate;
        dueDate.addDays(3);

        book1.borrowBook(member,dueDate);
        book2.borrowBook(member,dueDate);

        REQUIRE(book1.getDueDate().getYear() == 2024);
        REQUIRE(book1.getDueDate().getMonth() == 1);
        REQUIRE(book1.getDueDate().getDay() == 23);

        auto& booksLoaned = member.getBooksLoaned();
        book1.returnBook();
        REQUIRE(booksLoaned.size() == 1);
        REQUIRE(booksLoaned[0].getBookId() == 2);
    }


}

TEST_CASE("Book Borrow and Return Tests for Member", "[Member]") {
    Member member(123, "John Doe", "123 Street", "johndoe@example.com");
    Book book1(1, "Book One", "Author1", "Author1Last");
    Book book2(2, "Book Two", "Author2", "Author2Last");

    SECTION("Borrow Books") {
        member.setBookBorrowed(book1);
        member.setBookBorrowed(book2);

        auto& booksLoaned = member.getBooksLoaned();
        REQUIRE(booksLoaned.size() == 2);
        REQUIRE(booksLoaned[0].getBookId() == 1);
        REQUIRE(booksLoaned[1].getBookId() == 2);
    }


}