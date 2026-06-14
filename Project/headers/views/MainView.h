#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <string>

class MainView {
private:
    void printLine(char symbol) const;
    int readInt(const std::string& message) const;

public:
    void showWelcome() const;
    int askMainMenuOption() const;
    int askAuthenticatedMenuOption() const;
    void showInvalidOption() const;
    void showGoodbye() const;
    void showLogoutMessage() const;
    void showError(const std::string& message) const;
};

#endif