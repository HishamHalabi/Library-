class User {
private:
    string name;
    int age;
    int id;
    string password;
    string email;

public:
    static int count;

    User() : name(""), age(0), id(++count), password(""), email("") {}
    User(string name, int age, string password, string email) : name(name), age(age), id(++count), password(password), email(email) {}
    User(const User& user) : name(user.name), age(user.age), id(user.id), password(user.password), email(user.email) {}

    bool operator==(const User& other) { return id == other.id; }

    void setName(string name) { this->name = name; }
    string getName() const { return name; }

    void setPassword(string password) { this->password = password; }
    string getPassword() const { return password; }

    void setEmail(string email) { this->email = email; }
    string getEmail() const { return email; }

    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }

    int getId() const { return id; }

    void display() const {
        cout << "User Name: " << name << "\nAge: " << age << "\nID: " << id << "\nEmail: " << email << endl;
    }

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "Name: " << user.name << "\nAge: " << user.age << "\nID: " << user.id << "\nEmail: " << user.email;
        return os;
    }

    friend istream& operator>>(istream& is, User& user) {
        cout << "Enter Name: ";
        is >> user.name;
        cout << "Enter Age: ";
        is >> user.age;
        cout << "Enter Email: ";
        is >> user.email;
        cout << "Enter Password: ";
        is >> user.password;
        return is;
    }
};
