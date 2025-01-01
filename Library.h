#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include <list>
#include <string>
#include "Book.h"
#include "User.h"
#include "Transaction.h"
#include "BookBST.h"

class Library {
private:
    BookBST bookBST;
    std::unordered_map<int, User*> users;
    std::unordered_map<std::string, std::list<Book*>> booksByCategory;

public:
    void addBook(int id, std::string title, std::string author, std::string category) {
        Book* book = new Book(id, title, author, category);
        bookBST.insert(book);
        booksByCategory[category].push_back(book);
    }

    void addUser(int id, std::string name) {
        users[id] = new User(id, name);
    }

    bool borrowBook(int userId, int bookId) {
        Book* book = bookBST.search(bookId);
        if (!book || !book->available) return false;
        if (users.find(userId) == users.end()) return false;

        book->available = false;
        users[userId]->borrowedBooks[bookId] = book;
        users[userId]->addTransaction("Borrowed", book);
        return true;
    }

    bool returnBook(int userId, int bookId) {
        if (users.find(userId) == users.end()) return false;
        if (users[userId]->borrowedBooks.find(bookId) == users[userId]->borrowedBooks.end()) return false;

        Book* book = users[userId]->borrowedBooks[bookId];
        book->available = true;
        users[userId]->borrowedBooks.erase(bookId);
        users[userId]->addTransaction("Returned", book);
        return true;
    }

    void searchBookByTitle(std::string title) {
        bookBST.inorder();
    }

    void searchBookByCategory(std::string category) {
        if (booksByCategory.find(category) != booksByCategory.end()) {
            for (auto& book : booksByCategory[category]) {
                std::cout << book->id << ": " << book->title << "\n";
            }
        } else {
            std::cout << "No books found in this category.\n";
        }
    }

    void printUserHistory(int userId) {
        if (users.find(userId) != users.end()) {
            std::cout << "Transaction history for " << users[userId]->name << ":\n";
            for (const auto& transaction : users[userId]->transactionHistory) {
                std::cout << transaction.action << ": " << transaction.book->title << "\n";
            }
        }
    }

    void saveData() {
        std::ofstream file("data/library_data.txt");
        bookBST.inorder();
        for (auto& user : users) {
            file << user.second->id << "," << user.second->name << "\n";
            for (auto& borrowed : user.second->borrowedBooks) {
                file << borrowed.first << ",";
            }
            file << "\n";
        }
        file.close();
    }

    void loadData() {
        std::ifstream file("data/library_data.txt");
        std::string line;
        while (getline(file, line)) {
            // Data parsing logic
        }
        file.close();
    }
};

#endif
