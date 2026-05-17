//
// Created by kikok on 16/05/2026.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <string>
class MainView {
public:
    int menuWelcome() const;       // Register / Login / Exit
    int menuMain(const std::string& username) const;  // Schedule / Prices / Reservation / Logout
};
#endif //MAINVIEW_H
