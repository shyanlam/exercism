#pragma once
#include <mutex>
#include <optional>
namespace Bankaccount {
    enum class AccountState {
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
        static constexpr auto ACCOUNT_ALREADY_OPEN{ "Account already open." };
        static constexpr auto ACCOUNT_NOT_OPEN{ "Account is not open." };
        static constexpr auto NEGATIVE_AMOUNT{ "Negative amount." };
        static constexpr auto INSUFFICIENT_FUNDS{ "Insufficient funds." };
        mutable std::mutex _m{};
        std::optional<AccountState> _state{};
        double _balance{ 0 };

    };  // class Bankaccount
}  // namespace Bankaccount
