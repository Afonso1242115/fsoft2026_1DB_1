#include "User.h"
#include "Exceptions.h"

User::User(int id,
           const std::string& name,
           const std::string& email,
           const std::string& password) {
    this->id = id;
    setName(name);
    setEmail(email);
    setPassword(password);
}

//verifica se o nome é válido
bool User::isNameValid(const std::string& name) {
    return name.length() >= 3;
}

//verifica se o email é válido
bool User::isEmailValid(const std::string& email) {
    return email.find('@') != std::string::npos &&
           email.find('.') != std::string::npos;
}

//verifica se a password é válida
//min: 8 characters
//1 uppercase letter
//1 lowercase letter
//1 número
bool User::isPasswordValid(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNumber = false;

    //verifica cada caracter
    for (char character : password) {
        if (character >= 'A' && character <= 'Z') {
            hasUppercase = true;
        } else if (character >= 'a' && character <= 'z') {
            hasLowercase = true;
        } else if (character >= '0' && character <= '9') {
            hasNumber = true;
        }
    }

    return hasUppercase && hasLowercase && hasNumber;
}

//retorna o user id
int User::getId() const {
    return id;
}

//retorna o username
const std::string& User::getName() const {
    return name;
}


//retorna o email
const std::string& User::getEmail() const {
    return email;
}

//muda o username e só muda se for válido
void User::setName(const std::string& name) {
    if (!isNameValid(name)) {
        throw InvalidDataException("Name must have at least 3 characters");
    }

    this->name = name;
}

//muda o email e só muda se for válido
void User::setEmail(const std::string& email) {
    if (!isEmailValid(email)) {
        throw InvalidDataException("Email must contain @ and .");
    }

    this->email = email;
}

//muda a password e só é mudada se for válida
void User::setPassword(const std::string& password) {
    if (!isPasswordValid(password)) {
        throw InvalidDataException(
            "Password must have at least 8 characters, one uppercase letter, one lowercase letter and one number"
        );
    }

    this->password = password;
}

//verifica se a password colocada pelo user durante o login é válida
bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}

//compara o user com o id
bool User::operator==(int id) const {
    return this->id == id;
}

//compara o user com o email
bool User::operator==(const std::string& email) const {
    return this->email == email;
}