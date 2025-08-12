#include "bank_account.h"
#include <stdexcept>
namespace Bankaccount {
    void Bankaccount::open() {
        if (_state && _state == AccountState::Opened)
            throw std::runtime_error(INVALID_OP);
        _m.lock();
        _state = AccountState::Opened;
        _m.unlock();
    }

    double Bankaccount::balance() const {
        if (_state != AccountState::Opened)
            throw std::runtime_error(INVALID_OP);
        std::unique_lock<std::mutex> lock(_m);
        return _balance;
    }

    void Bankaccount::close() {
        if (_state != AccountState::Opened)
            throw std::runtime_error(INVALID_OP);
        std::unique_lock<std::mutex> lock(_m);
        _state = AccountState::Closed;
        _balance = 0.0;
    }
    void Bankaccount::deposit(double amount) {
        if (_state != AccountState::Opened)
            throw std::runtime_error(INVALID_OP);
        if (amount < 0.0)
            throw std::runtime_error(INVALID_AMOUNT);
        std::unique_lock<std::mutex> lock(_m);
        _balance += amount;
    }

    void Bankaccount::withdraw(double amount) {
        if (_state != AccountState::Opened)
            throw std::runtime_error(INVALID_OP);
        if (amount < 0.0 || amount > _balance)
            throw std::runtime_error(INVALID_AMOUNT);
        std::unique_lock<std::mutex> lock(_m);
        _balance -= amount;
    }
}