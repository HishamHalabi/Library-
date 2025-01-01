#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Book.h"

class Transaction {
public:
    std::string action;
    Book* book;

    Transaction(std::string action, Book* book) : action(action), book(book) {}
};

#endif
