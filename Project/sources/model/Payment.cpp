#include "Payment.h"

Payment::Payment() : method("None"), amount(0.0) {}
Payment::Payment(const std::string& method, double amount) : method(method), amount(amount) {}
const std::string& Payment::getMethod() const { return method; }
double Payment::getAmount() const { return amount; }
