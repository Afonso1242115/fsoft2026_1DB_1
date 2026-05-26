#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <string>

class MainView {
private:
    void printLine(char symbol) const;
    int readInt(const std::string& message) const;

public:
    void showWelcome() const;
    void showHeader(const std::string& title) const;

    int askMainMenuOption() const;
    int askUserMenuOption() const;

    void showInvalidOption() const;
    void showLogoutMessage() const;
    void showGoodbye() const;
    void showError(const std::string& message) const;
};

#endif
