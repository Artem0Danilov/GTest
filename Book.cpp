#include <gtest/gtest.h>
#include "Book.h"

int Book::count = 0;

Book::Book(const std::string& title, const std::string& author, const std::string& info, bool isAvailable)
	: title(title), author(author), info(info), isAvailable(isAvailable), id(++count) {}

std::string Book::getTitle() const {
	return title;
}

std::string Book::getAuthor() const {
	return author;
}

std::string Book::getInfo() const {
	return info;
}

bool Book::getAvailability() const {
	return isAvailable;
}

int Book::getID() const {
	return id;
}

void Book::setTitle(const std::string& title) {
	this->title = title;
}

void Book::setAuthor(const std::string& author) {
	this->author = author;
}

void Book::setInfo(const std::string& info) {
	this->info = info;
}

void Book::addInfo(const std::string& info) {
	this->info += info;
}

void Book::setAvailability(bool isAvailable) {
	this->isAvailable = isAvailable;
}

// Test the constructor and initialization
TEST(BookTest, ConstructorTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getInfo(), "Dystopian novel");
    EXPECT_TRUE(book.getAvailability());
    EXPECT_EQ(book.getID(), 1); // Assuming this is the first book created (ID starts at 1)
}

// Test getter and setter methods
TEST(BookTest, GetterSetterTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    book.setTitle("Animal Farm");
    book.setAuthor("George Orwell");
    book.setInfo("Another dystopian novel");
    book.setAvailability(false);

    EXPECT_EQ(book.getTitle(), "Animal Farm");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getInfo(), "Another dystopian novel");
    EXPECT_FALSE(book.getAvailability());
}

// Test the addInfo method
TEST(BookTest, AddInfoTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    book.addInfo(" - A political warning");

    EXPECT_EQ(book.getInfo(), "Dystopian novel - A political warning");

    // Test the addInfo with an already populated 'info'
    book.addInfo(" - A timeless classic");

    EXPECT_EQ(book.getInfo(), "Dystopian novel - A political warning - A timeless classic");

    // If the info is not empty, addInfo shouldn't append
    book.setInfo("");
    book.addInfo("Test info");

    EXPECT_EQ(book.getInfo(), "Test info");
}

// Test ID counter increments correctly
TEST(BookTest, IDIncrementTest) {
    Book book1("Book1", "Author1", "Info1", true);
    Book book2("Book2", "Author2", "Info2", false);

    EXPECT_EQ(book1.getID(), 1);  // First book should have ID 1
    EXPECT_EQ(book2.getID(), 2);  // Second book should have ID 2
}

// Test availability flag toggle
TEST(BookTest, AvailabilityTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    book.setAvailability(false);
    EXPECT_FALSE(book.getAvailability());

    book.setAvailability(true);
    EXPECT_TRUE(book.getAvailability());
}