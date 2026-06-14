#ifndef USERMAPPER_H
#define USERMAPPER_H

#include "User.h"
#include "UserDTO.h"

class UserMapper {
public:
    static UserDTO modelToDTO(const User* user);
};

#endif
