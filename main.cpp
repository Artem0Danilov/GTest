#include <gtest/gtest.h>
#include "Book.h"

// ���� ��� ������������ � ������ getTitle
TEST(BookTest, ConstructorAndGetTitle) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getTitle(), "1984");
}

// ���� ��� ������������ � ������ getAuthor
TEST(BookTest, ConstructorAndGetAuthor) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getAuthor(), "George Orwell");
}

// ���� ��� ������������ � ������ getInfo
TEST(BookTest, ConstructorAndGetInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getInfo(), "Dystopian novel");
}

// ���� ��� ������������ � ������ getAvailability
TEST(BookTest, ConstructorAndGetAvailability) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_TRUE(book.getAvailability());

    Book bookUnavailable("1984", "George Orwell", "Dystopian novel", false);
    EXPECT_FALSE(bookUnavailable.getAvailability());
}

// ���� ��� ������ setTitle
TEST(BookTest, SetTitle) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setTitle("Animal Farm");
    EXPECT_EQ(book.getTitle(), "Animal Farm");
}

// ���� ��� ������ setAuthor
TEST(BookTest, SetAuthor) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setAuthor("Aldous Huxley");
    EXPECT_EQ(book.getAuthor(), "Aldous Huxley");
}

// ���� ��� ������ setInfo
TEST(BookTest, SetInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setInfo("A new information about the book.");
    EXPECT_EQ(book.getInfo(), "A new information about the book.");
}

// ���� ��� ������ addInfo
TEST(BookTest, AddInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.addInfo(" Published in 1949.");
    EXPECT_EQ(book.getInfo(), "Dystopian novel Published in 1949.");
}

// ���� ��� ������ setAvailability
TEST(BookTest, SetAvailability) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setAvailability(false);
    EXPECT_FALSE(book.getAvailability());
}

// ���� ��� ������������ ID
TEST(BookTest, UniqueID) {
    Book book1("1984", "George Orwell", "Dystopian novel", true);
    Book book2("Animal Farm", "George Orwell", "Allegorical novel", true);
    EXPECT_NE(book1.getID(), book2.getID());
}

// ���� ��� �������� ������������ ID ��� �������� ����
TEST(BookTest, IDIncrement) {
    Book book1("1984", "George Orwell", "Dystopian novel", true);
    Book book2("Animal Farm", "George Orwell", "Allegorical novel", true);
    EXPECT_EQ(book2.getID(), book1.getID() + 1);
}

