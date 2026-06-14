#ifndef USERDTO_H
#define USERDTO_H

#include <string>

class UserDTO {
public:
    int id;
    std::string name;
    std::string email;

    UserDTO() : id(0) {

    }
    UserDTO(int id, const std::string& name, const std::string& email)
        : id(id), name(name), email(email) {

    }
};

#endif