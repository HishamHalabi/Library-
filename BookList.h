

class BookList {
private:
    Book* books;
    int capacity;
    int booksCount;

public:
    BookList() : books(nullptr), capacity(0), booksCount(0) {}
    BookList(int capacity) : capacity(capacity), booksCount(0) {
        books = new Book[capacity];
    }

    void addBook(const Book& book) {
        if (booksCount < capacity) {
            books[booksCount++] = book;
        } else {
            cout << "Book list is full!" << endl;
        }
    }

    Book* searchBook(string title) {
        for (int i = 0; i < booksCount; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Book* searchBook(int id) {
        for (int i = 0; i < booksCount; i++) {
            if (books[i].getId() == id) {
                return &books[i];
            }
        }
        return nullptr;
    }

    void deleteBook(int id) {
        for (int i = 0; i < booksCount; i++) {
            if (books[i].getId() == id) {
                for (int j = i; j < booksCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                booksCount--;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    Book getTheHighestRatedBook() {
        if (booksCount == 0) {
            throw runtime_error("No books in the list.");
        }
        Book* highestRated = &books[0];
        for (int i = 1; i < booksCount; i++) {
            if (books[i].getAverageRating() > highestRated->getAverageRating()) {
                highestRated = &books[i];
            }
        }
        return *highestRated;
    }

    void getBooksForUser(const User& author) {
        for (int i = 0; i < booksCount; i++) {
            if (books[i].getAuthor() == author) {
                cout << books[i] << endl;
            }
        }
    }

    Book& operator[](int index) {
        if (index >= 0 && index < booksCount) {
            return books[index];
        }
        throw out_of_range("Index out of range.");
    }

    friend ostream& operator<<(ostream& os, const BookList& bookList) {
        for (int i = 0; i < bookList.booksCount; i++) {
            os << bookList.books[i] << "\n";
        }
        return os;
    }

    ~BookList() {
        delete[] books;
    }
