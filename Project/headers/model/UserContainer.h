#ifndef USERCONTAINER_H
#define USERCONTAINER_H

#include "User.h"
#include <vector>

class UserContainer {
private:
    std::vector<User> users;
    int nextId;

    User* searchByEmail(const std::string& email);

public:
    UserContainer();

    void add(const std::string& name,
             const std::string& email,
             const std::string& password);

    User* login(const std::string& email,
                const std::string& password);
};

#endif
