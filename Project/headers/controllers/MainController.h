//
// Created by kikok on 16/05/2026.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/Cinema.h"
#include "../model/User.h"
#include "../model/Reservation.h"
#include "../views/mainView.h"
#include "movieController.h"
#include "sessionController.h"
#include "userController.h"
#include "reservationController.h"
#include <vector>

class MainController {
private:
    Cinema model;
    std::vector<User> users;
    std::vector<Reservation> reservations;

    MainView view;
    MovieController movieController;
    SessionController sessionController;
    UserController userController;
    ReservationController reservationController;

    void seedData();

public:
    MainController();
    void run();
};
#endif //CONTROLLER_H
