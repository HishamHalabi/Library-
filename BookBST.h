#ifndef BOOKBST_H
#define BOOKBST_H

#include "Book.h"
#include <iostream>

class BSTNode {
public:
    Book* book;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Book* book) : book(book), left(nullptr), right(nullptr) {}
};

class BookBST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, Book* book) {
        if (node == nullptr) {
            return new BSTNode(book);
        }
        if (book->id < node->book->id) {
            node->left = insert(node->left, book);
        } else if (book->id > node->book->id) {
            node->right = insert(node->right, book);
        }
        return node;
    }

    BSTNode* search(BSTNode* node, int bookId) {
        if (node == nullptr || node->book->id == bookId) {
            return node;
        }
        if (bookId < node->book->id) {
            return search(node->left, bookId);
        }
        return search(node->right, bookId);
    }

    void inorder(BSTNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->book->id << ": " << node->book->title << "\n";
            inorder(node->right);
        }
    }

public:
    BookBST() : root(nullptr) {}

    void insert(Book* book) {
        root = insert(root, book);
    }

    Book* search(int bookId) {
        BSTNode* node = search(root, bookId);
        return node ? node->book : nullptr;
    }

    void inorder() {
        inorder(root);
    }
};

#endif
