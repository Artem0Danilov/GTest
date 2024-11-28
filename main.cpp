#include <gtest/gtest.h>
#include "Book.h"

// Тест для конструктора и метода getTitle
TEST(BookTest, ConstructorAndGetTitle) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getTitle(), "1984");
}

// Тест для конструктора и метода getAuthor
TEST(BookTest, ConstructorAndGetAuthor) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getAuthor(), "George Orwell");
}

// Тест для конструктора и метода getInfo
TEST(BookTest, ConstructorAndGetInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_EQ(book.getInfo(), "Dystopian novel");
}

// Тест для конструктора и метода getAvailability
TEST(BookTest, ConstructorAndGetAvailability) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    EXPECT_TRUE(book.getAvailability());

    Book bookUnavailable("1984", "George Orwell", "Dystopian novel", false);
    EXPECT_FALSE(bookUnavailable.getAvailability());
}

// Тест для метода setTitle
TEST(BookTest, SetTitle) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setTitle("Animal Farm");
    EXPECT_EQ(book.getTitle(), "Animal Farm");
}

// Тест для метода setAuthor
TEST(BookTest, SetAuthor) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setAuthor("Aldous Huxley");
    EXPECT_EQ(book.getAuthor(), "Aldous Huxley");
}

// Тест для метода setInfo
TEST(BookTest, SetInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setInfo("A new information about the book.");
    EXPECT_EQ(book.getInfo(), "A new information about the book.");
}

// Тест для метода addInfo
TEST(BookTest, AddInfo) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.addInfo(" Published in 1949.");
    EXPECT_EQ(book.getInfo(), "Dystopian novel Published in 1949.");
}

// Тест для метода setAvailability
TEST(BookTest, SetAvailability) {
    Book book("1984", "George Orwell", "Dystopian novel", true);
    book.setAvailability(false);
    EXPECT_FALSE(book.getAvailability());
}

// Тест для уникальности ID
TEST(BookTest, UniqueID) {
    Book book1("1984", "George Orwell", "Dystopian novel", true);
    Book book2("Animal Farm", "George Orwell", "Allegorical novel", true);
    EXPECT_NE(book1.getID(), book2.getID());
}

// Тест для проверки корректности ID при создании книг
TEST(BookTest, IDIncrement) {
    Book book1("1984", "George Orwell", "Dystopian novel", true);
    Book book2("Animal Farm", "George Orwell", "Allegorical novel", true);
    EXPECT_EQ(book2.getID(), book1.getID() + 1);
}

