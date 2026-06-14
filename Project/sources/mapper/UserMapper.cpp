#include "UserMapper.h"

UserDTO UserMapper::modelToDTO(const User* user) {
    if (user == nullptr) return UserDTO();
    return UserDTO(user->getId(), user->getName(), user->getEmail());
}
