#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(int id, const std::string& name, const std::string& email, const std::string& password);

    static bool isNameValid(const std::string& name);
    static bool isEmailValid(const std::string& email);
    static bool isPasswordValid(const std::string& password);

    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);
    bool checkPassword(const std::string& password) const;

    bool operator==(int id) const;
    bool operator==(const std::string& email) const;
};

#endif
