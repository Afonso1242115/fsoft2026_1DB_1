#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
private:
    std::string method;
    double amount;

public:
    Payment();
    Payment(const std::string& method, double amount);
    const std::string& getMethod() const;
    double getAmount() const;
};

#endif
