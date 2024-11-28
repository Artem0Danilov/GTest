#pragma once

#include <iostream>

class Book {
public:
    explicit Book(const std::string& title = "No Title",
                  const std::string& author = "No Author",
                  const std::string& info = "",
                  bool isAvailable = true);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getInfo() const;
    bool getAvailability() const;
    int getID() const; // each book has its own unique id

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setInfo(const std::string& info); // replace old info with new info
    void addInfo(const std::string& info); // concatenate old info with new info
    void setAvailability(bool isAvailable);

private:
    std::string title;
    std::string author;
    std::string info;
    bool isAvailable;
    const int id;
    static int count; // for creating book id
};
