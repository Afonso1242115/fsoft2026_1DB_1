#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string username;
    std::string email;
    std::string password;
    int failedAttempts;
    bool locked;

public:
    User(int id, const std::string& username,
         const std::string& email, const std::string& password);

    int getId() const;
    std::string getUsername() const;
    std::string getEmail() const;
    bool isLocked() const;

    bool checkPassword(const std::string& password);
    void registerFailedAttempt();
    void resetAttempts();

    static bool validatePassword(const std::string& password);
    static bool validateEmail(const std::string& email);

    std::string toString() const;
};
#endif
