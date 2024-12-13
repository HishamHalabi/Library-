
class UserList {
private:
    User* users;
    int capacity;
    int usersCount;

public:
    UserList() : users(nullptr), capacity(0), usersCount(0) {}
    UserList(int capacity) : capacity(capacity), usersCount(0) {
        users = new User[capacity];
    }

    void addUser(User& user) {
        if (usersCount < capacity) {
            users[usersCount++] = user;
        } else {
            cout << "User list is full!" << endl;
        }
    }

    User* searchUser(string email) {
        for (int i = 0; i < usersCount; i++) {
            if (users[i].getEmail() == email) {
                return &users[i];
            }
        }
        return nullptr;
    }

    User* searchUser(int id) {
        for (int i = 0; i < usersCount; i++) {
            if (users[i].getId() == id) {
                return &users[i];
            }
        }
        return nullptr;
    }

    void deleteUser(int id) {
        for (int i = 0; i < usersCount; i++) {
            if (users[i].getId() == id) {
                for (int j = i; j < usersCount - 1; j++) {
                    users[j] = users[j + 1];
                }
                usersCount--;
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    friend ostream& operator<<(ostream& os, const UserList& userList) {
        for (int i = 0; i < userList.usersCount; i++) {
            os << userList.users[i] << "\n";
        }
        return os;
    }

    ~UserList() {
        delete[] users;
    }
};
