#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    std::string category;
    bool available;

    Book(int id, std::string title, std::string author, std::string category)
        : id(id), title(title), author(author), category(category), available(true) {}
};

#endif
