#ifndef CINEMA_H
#define CINEMA_H

#include "User.h"

class Cinema {
public:
    Cinema();

    void seedData();
    void listReservationsByUser(User* user) const;
};

#endif