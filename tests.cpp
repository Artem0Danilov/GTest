#include "gtest/gtest.h"
#include "Book.h"  // Include your Book class header file

// Test Fixture for Book class
class BookTest : public ::testing::Test {
protected:
    // You can set up common test data here
    void SetUp() override {
        book1 = new Book("1984", "George Orwell", "Dystopian novel", true);
        book2 = new Book("Brave New World", "Aldous Huxley", "Dystopian novel", false);
    }

    void TearDown() override {
        // This will run after each test
        delete book1;
        delete book2;
    }

    Book* book1;
    Book* book2;
};

// Test constructor and getters
TEST_F(BookTest, ConstructorAndGettersTest) {
    EXPECT_EQ(book1->getTitle(), "1984");
    EXPECT_EQ(book1->getAuthor(), "George Orwell");
    EXPECT_EQ(book1->getInfo(), "Dystopian novel");
    EXPECT_EQ(book1->getAvailability(), true);
    EXPECT_EQ(book1->getID(), 1); // Assuming this is the first book created

    EXPECT_EQ(book2->getTitle(), "Brave New World");
    EXPECT_EQ(book2->getAuthor(), "Aldous Huxley");
    EXPECT_EQ(book2->getInfo(), "Dystopian novel");
    EXPECT_EQ(book2->getAvailability(), false);
}

// Test setters
TEST_F(BookTest, SettersTest) {
    book1->setTitle("Animal Farm");
    book1->setAuthor("George Orwell");
    book1->setInfo("Political allegory");
    book1->setAvailability(false);

    EXPECT_EQ(book1->getTitle(), "Animal Farm");
    EXPECT_EQ(book1->getAuthor(), "George Orwell");
    EXPECT_EQ(book1->getInfo(), "Political allegory");
    EXPECT_EQ(book1->getAvailability(), false);
}

// Test addInfo method
TEST_F(BookTest, AddInfoTest) {
    book1->addInfo(" - Published in 1945.");
    EXPECT_EQ(book1->getInfo(), "Dystopian novel - Published in 1945.");
}

// Test unique book ID increments
TEST_F(BookTest, IDTest) {
    Book book3("Fahrenheit 451", "Ray Bradbury", "Dystopian novel", true);
    EXPECT_EQ(book3.getID(), 3);  // ID should increment with each new book created
}

// Test availability
TEST_F(BookTest, AvailabilityTest) {
    EXPECT_TRUE(book1->getAvailability());
    EXPECT_FALSE(book2->getAvailability());
    book1->setAvailability(false);
    EXPECT_FALSE(book1->getAvailability());
}

// You can add more tests here based on your class methods
