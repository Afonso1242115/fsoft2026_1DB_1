#include "SessionMapper.h"

SessionDTO SessionMapper::modelToDTO(const Session& session) {
    return SessionDTO(session.getId(), session.getMovieId(), session.getRoom(), session.getTime(), session.getBasePrice());
}

std::vector<SessionDTO> SessionMapper::listToDTO(const std::vector<Session>& sessions) {
    std::vector<SessionDTO> dtos;
    for (const Session& session : sessions) dtos.push_back(modelToDTO(session));
    return dtos;
}
