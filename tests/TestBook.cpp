#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "Book.h"
#include "Member.h"
#include "Date.h"

TEST_CASE("Book Creation and Property Tests", "[Book]") {
    Book book(1, "Test Book", "John", "Doe");
    REQUIRE(book.getBookId() == 1);
    REQUIRE(book.getName() == "Test Book");
    REQUIRE(book.getAuthorFirstName() == "John");
    REQUIRE(book.getAuthorLastName() == "Doe");

    // Test setters
    book.setBookId(2);
    book.setName("New Title");
    book.setAuthorFirstName("Jane");
    book.setAuthorLastName("Smith");

    REQUIRE(book.getBookId() == 2);
    REQUIRE(book.getName() == "New Title");
    REQUIRE(book.getAuthorFirstName() == "Jane");
    REQUIRE(book.getAuthorLastName() == "Smith");
}

    TEST_CASE("Book Borrow and Return Tests", "[Book]") {
    Book book(1, "Test Book", "John", "Doe");
    Member member(1, "MemberName", "MemberSurname", "MemberEmail");
    Date dueDate;

    SECTION("Borrow Book") {
        book.borrowBook(member, dueDate);
        REQUIRE(member.getMemberId() == 1);
        REQUIRE(member.getName() == "MemberName");
    }

    SECTION("Return Book") {
        book.borrowBook(member, dueDate);
        book.returnBook();
        REQUIRE(member.getBooksLoaned().empty());

    }


}