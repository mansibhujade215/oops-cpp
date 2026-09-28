#include <iostream>
// Includes input/output library.
// Provides cout and endl.

#include <memory>
// Provides smart pointers like unique_ptr
// and make_unique().

#include <string>
// Provides string data type.

#include <vector>
// Provides vector container.

using namespace std;
// Allows us to use cout, string, vector, etc.
// without writing std::


class PaymentMethod {
// Base class for all payment methods.

protected:

    string transactionId;
    // Stores transaction ID.

    double amount;
    // Stores payment amount.


public:

    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    // Constructor of PaymentMethod.
    // tid = transaction ID.
    // amt = payment amount.
    // : = member initializer list.


    virtual bool processPayment() const = 0;

    // virtual = enables runtime polymorphism.
    // bool = returns true or false.
    // processPayment = function name.
    // const = does not modify object.
    // = 0 = pure virtual function.
    //
    // This makes PaymentMethod an abstract class.


    virtual ~PaymentMethod() = default;

    // Virtual destructor.
    // = default means compiler creates it automatically.
};


// Credit Card Payment class

class CreditCardPayment : public PaymentMethod {

private:

    string maskedCardNumber;
    // Stores masked card number.


public:

    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt),
          maskedCardNumber(card) {}

    // Calls base-class constructor.
    // Initializes masked card number.


    bool processPayment() const override {

        // Overrides processPayment() from base class.

        cout << "Credit-card transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " using "
             << maskedCardNumber
             << " completed."
             << endl;

        // Displays credit-card transaction details.

        return true;
        // Payment successful.
    }
};


// UPI Payment class

class UPIPayment : public PaymentMethod {

private:

    string upiId;
    // Stores UPI ID.


public:

    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt),
          upiId(upi) {}

    // Calls PaymentMethod constructor.
    // Initializes UPI ID.


    bool processPayment() const override {

        // Overrides base-class function.

        cout << "UPI transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " from "
             << upiId
             << " completed."
             << endl;

        // Displays UPI transaction.

        return true;
        // Payment successful.
    }
};


// Net Banking Payment class

class NetBankingPayment : public PaymentMethod {

private:

    string bankName;
    // Stores bank name.


public:

    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt),
          bankName(bank) {}

    // Calls base-class constructor.
    // Initializes bank name.


    bool processPayment() const override {

        // Overrides processPayment().

        cout << "Net-banking transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " through "
             << bankName
             << " completed."
             << endl;

        // Displays net-banking transaction.

        return true;
        // Payment successful.
    }
};


int main() {

    // Program execution starts here.


    vector<unique_ptr<PaymentMethod>> payments;

    // vector = stores multiple values.
    // unique_ptr = smart pointer.
    // PaymentMethod = base class.
    // payments = vector name.
    //
    // This vector can store different derived
    // payment objects using the base-class pointer.


    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001",
            2500,
            "XXXX-XXXX-1234"
        )
    );

    // Creates CreditCardPayment object
    // and adds it to the vector.


    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002",
            1200,
            "student@upi"
        )
    );

    // Creates UPI payment object
    // and adds it to the vector.


    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003",
            5000,
            "Example Bank"
        )
    );

    // Creates Net Banking payment object
    // and adds it to the vector.


    cout << "=== Payment Gateway ===" << endl;

    // Prints heading.


    for (const auto& payment : payments) {

        // for = loop.
        // const = cannot modify the object.
        // auto = compiler automatically determines type.
        // & = reference.
        // payment = current payment object.


        payment->processPayment();

        // -> accesses function through pointer.
        // Calls the appropriate processPayment()
        // according to the actual object.
        //
        // This is runtime polymorphism.
    }

}