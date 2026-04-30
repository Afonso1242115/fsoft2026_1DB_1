//
// Created by Afonso on 30/04/2026.
//
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string email;
    std::string password;

public:
    //Constructors
    User();
    User(const std::string& username, const std::string& email, const std::string& password);

    //Getters
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getEmail() const;
    [[nodiscard]] std::string getPassword() const;

    //Setters
    void setUsername(const std::string& username);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);

    //Methods
    [[nodiscard]] bool authenticate(const std::string& inputPassword) const;
};
#endif //USER_H
