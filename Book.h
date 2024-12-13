class Book {
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    int ratingCount;
    User author;

public:
    static int count;

    Book() : title(""), isbn(""), id(++count), category(""), averageRating(0.0), ratingCount(0) {}
    Book(string title, string isbn, string category) : title(title), isbn(isbn), id(++count), category(category), averageRating(0.0), ratingCount(0) {}
    Book(const Book& book) : title(book.title), isbn(book.isbn), id(book.id), category(book.category), averageRating(book.averageRating), ratingCount(book.ratingCount), author(book.author) {}

    void setTitle(string title) { this->title = title; }
    string getTitle() const { return title; }

    void setIsbn(string isbn) { this->isbn = isbn; }
    string getIsbn() const { return isbn; }

    void setId(int id) { this->id = id; }
    int getId() const { return id; }

    void setCategory(string category) { this->category = category; }
    string getCategory() const { return category; }

    void setAuthor(const User& author) { this->author = author; }
    User getAuthor() const { return author; }

    void rateBook(double rating) {
        if (rating >= 0 && rating <= 5) {
            averageRating = ((averageRating * ratingCount) + rating) / (ratingCount + 1);
            ratingCount++;
        }
    }

    double getAverageRating() const { return averageRating; }

    bool operator==(const Book& other) { return isbn == other.isbn; }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.title << "\nISBN: " << book.isbn << "\nID: " << book.id
           << "\nCategory: " << book.category << "\nAverage Rating: " << book.averageRating;
        return os;
    }

    friend istream& operator>>(istream& is, Book& book) {
        cout << "Enter Title: ";
        is >> book.title;
        cout << "Enter ISBN: ";
        is >> book.isbn;
        cout << "Enter Category: ";
        is >> book.category;
        return is;
    }
};
