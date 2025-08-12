#include "bank_account.h"
#include <stdexcept>
namespace Bankaccount {
    void Bankaccount::open() {
        if (_state && _state == AccountState::Opened)
            throw std::runtime_error(ACCOUNT_ALREADY_OPEN);
        _m.lock();
        _state = AccountState::Opened;
        _m.unlock();
    }

    double Bankaccount::balance() const {
        if (_state != AccountState::Opened)
            throw std::runtime_error(ACCOUNT_NOT_OPEN);
        std::unique_lock<std::mutex> lock(_m);
        return _balance;
    }

    void Bankaccount::close() {
        if (_state != AccountState::Opened)
            throw std::runtime_error(ACCOUNT_NOT_OPEN);
        std::unique_lock<std::mutex> lock(_m);
        _state = AccountState::Closed;
        _balance = 0.0;
    }
    void Bankaccount::deposit(double amount) {
        if (_state != AccountState::Opened)
            throw std::runtime_error(ACCOUNT_NOT_OPEN);
        if (amount < 0.0)
            throw std::runtime_error(NEGATIVE_AMOUNT);
        std::unique_lock<std::mutex> lock(_m);
        _balance += amount;
    }

    void Bankaccount::withdraw(double amount) {
        if (_state != AccountState::Opened)
            throw std::runtime_error(ACCOUNT_NOT_OPEN);
        if (amount < 0.0)
            throw std::runtime_error(NEGATIVE_AMOUNT);
        if (amount > _balance)
            throw std::runtime_error(INSUFFICIENT_FUNDS);

        std::unique_lock<std::mutex> lock(_m);
        _balance -= amount;
    }
}