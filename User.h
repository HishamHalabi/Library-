#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <list>
#include "Book.h"
#include "Transaction.h"

class User {
public:
    int id;
    std::string name;
    std::unordered_map<int, Book*> borrowedBooks;
    std::list<Transaction> transactionHistory;

    User(int id, std::string name);
    void addTransaction(std::string action, Book* book);
};

#endif
