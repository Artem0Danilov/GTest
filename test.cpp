#include "Book.h"
#include <gtest/gtest.h>

// Test Fixture for Book class
class BookTest : public ::testing::Test {
protected:
    // Set up code if needed (optional)
    void SetUp() override {
        // Initialize some Book objects here if needed
    }

    // Tear down code if needed (optional)
    void TearDown() override {
        // Clean up if necessary
    }
};

// Constructor Test
TEST_F(BookTest, ConstructorTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getInfo(), "Dystopian novel");
    EXPECT_TRUE(book.getAvailability());
}

// Getter Tests
TEST_F(BookTest, GetterTests) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getInfo(), "Dystopian novel");
    EXPECT_TRUE(book.getAvailability());
    EXPECT_EQ(book.getID(), 1);  // The first book should have ID 1
}

// Setter Tests
TEST_F(BookTest, SetterTests) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    book.setTitle("Animal Farm");
    book.setAuthor("George Orwell");
    book.setInfo("Political satire");
    book.setAvailability(false);

    EXPECT_EQ(book.getTitle(), "Animal Farm");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getInfo(), "Political satire");
    EXPECT_FALSE(book.getAvailability());
}

// ID Increment Test
TEST_F(BookTest, IDIncrementTest) {
    Book book1("1984", "George Orwell", "Dystopian novel", true);
    Book book2("Brave New World", "Aldous Huxley", "Dystopian novel", true);

    EXPECT_EQ(book1.getID(), 1);
    EXPECT_EQ(book2.getID(), 2);  // ID should increment for each new Book object
}

// addInfo Method Test
TEST_F(BookTest, AddInfoTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    // Add more information to the existing info
    book.addInfo(" - A critical look at totalitarianism.");

    EXPECT_EQ(book.getInfo(), "Dystopian novel - A critical look at totalitarianism.");
}

// Availability Test
TEST_F(BookTest, AvailabilityTest) {
    Book book("1984", "George Orwell", "Dystopian novel", true);

    EXPECT_TRUE(book.getAvailability());

    // Change availability
    book.setAvailability(false);
    EXPECT_FALSE(book.getAvailability());
}

