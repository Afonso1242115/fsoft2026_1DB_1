#ifndef SESSIONMAPPER_H
#define SESSIONMAPPER_H

#include "Session.h"
#include "SessionDTO.h"
#include <vector>

class SessionMapper {
public:
    static SessionDTO modelToDTO(const Session& session);
    static std::vector<SessionDTO> listToDTO(const std::vector<Session>& sessions);
};

#endif
