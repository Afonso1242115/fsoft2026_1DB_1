//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_PAYMENT_H
#define MOVIETICKETSYSTEM_PAYMENT_H
#include <string>

enum PaymentStatus { PENDING, APPROVED, DECLINED };

class Payment {
private:
    int id;
    double amount;
    std::string method;
    std::string paymentDate;
    PaymentStatus status;
    std::string maskedCardNumber;

public:
    Payment(int id, double amount, const std::string& method);

    int getId() const;
    double getAmount() const;
    std::string getMethod() const;
    PaymentStatus getStatus() const;
    std::string getPaymentDate() const;

    bool process(const std::string& cardNumber,
                 const std::string& expiry,
                 const std::string& cvv);

    static bool validateCard(const std::string& cardNumber,
                              const std::string& expiry,
                              const std::string& cvv);

    std::string toString() const;
};
#endif //MOVIETICKETSYSTEM_PAYMENT_H
