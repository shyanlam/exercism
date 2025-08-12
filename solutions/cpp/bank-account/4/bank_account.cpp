#include "bank_account.h"
#include <stdexcept>
namespace Bankaccount {

    void Bankaccount::check_and_throw(bool condition, const std::string& message) const {
        if (!condition)
            throw std::runtime_error(message);
    }

    void Bankaccount::open() {
        check_and_throw(!_state || _state == AccountState::Closed, ACCOUNT_ALREADY_OPEN);
        _m.lock();
        _state = AccountState::Opened;
        _m.unlock();
    }

    double Bankaccount::balance() const {
        check_and_throw(_state == AccountState::Opened, ACCOUNT_NOT_OPEN);
        std::lock_guard<std::mutex> lock(_m);
        return _balance;
    }

    void Bankaccount::close() {
        check_and_throw(_state == AccountState::Opened, ACCOUNT_NOT_OPEN);
        std::lock_guard<std::mutex> lock(_m);
        _state = AccountState::Closed;
        _balance = 0.0;
    }
    void Bankaccount::deposit(double amount) {
        check_and_throw(_state == AccountState::Opened, ACCOUNT_NOT_OPEN);
        check_and_throw(amount >= 0.0, ZERO_OR_NEGATIVE_AMOUNT);

        std::lock_guard<std::mutex> lock(_m);
        _balance += amount;
    }

    void Bankaccount::withdraw(double amount) {
        check_and_throw(_state == AccountState::Opened, ACCOUNT_NOT_OPEN);
        check_and_throw(amount >= 0.0, ZERO_OR_NEGATIVE_AMOUNT);
        check_and_throw(amount <= _balance, INSUFFICIENT_FUNDS);

        std::lock_guard<std::mutex> lock(_m);
        _balance -= amount;
    }
}