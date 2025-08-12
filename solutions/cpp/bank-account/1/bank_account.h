#pragma once
#include <mutex>
#include <string>
namespace Bankaccount {
    enum class AccountState {
        Init,
        Opened,
        Closed,
    };
    class Bankaccount {
    public:
        Bankaccount() = default;

        double balance() const;
        void open();
        void close();
        void deposit(double amount);
        void withdraw(double amount);

    private:
        static constexpr auto INVALID_OP{ "Invalid Operation." };
        static constexpr auto INVALID_AMOUNT{ "Invalid amount." };
        mutable std::mutex _m{};
        AccountState _state{ AccountState::Init };
        double _balance{ 0 };

    };  // class Bankaccount
}  // namespace Bankaccount
