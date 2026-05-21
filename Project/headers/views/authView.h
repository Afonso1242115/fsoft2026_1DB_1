#ifndef AUTHVIEW_H
#define AUTHVIEW_H

#include <string>
#include "../model/User.h"

class AuthView {
private:
    std::string readString(const std::string& message) const;

public:
    void showRegisterHeader() const;
    void showLoginHeader() const;

    std::string askName() const;
    std::string askEmail() const;
    std::string askPassword() const;

    void showInvalidName() const;
    void showInvalidEmail() const;
    void showInvalidPassword() const;

    void showRegisterSuccess() const;
    void showLoginSuccess(const User* user) const;
};

#endif