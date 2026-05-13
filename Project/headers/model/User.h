#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id; //cada user tem um identifier único
    std::string name;
    std::string email;
    std::string password;



public:
    //constructor usado para criar um user válido
    User(int id, const std::string& name, const std::string& email, const std::string& password);
    User(const User& user) = default;
    ~User() = default;

    //são static para validar os dados antes de criar o objeto User
    static bool isNameValid(const std::string& name);
    static bool isEmailValid(const std::string& email);
    static bool isPasswordValid(const std::string& password);

    //Getters
    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;


    //Setters, validam os dados antes de mudar o objeto
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);

    //operators usados para comparar e/ou procurar users
    bool operator==(int id) const;
    bool operator==(const std::string& email) const;

    bool checkPassword(const std::string& password) const; //usado durante o login
};

#endif
