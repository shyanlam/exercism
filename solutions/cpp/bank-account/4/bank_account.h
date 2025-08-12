#pragma once
#include <mutex>
#include <optional>
#include <string>
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
        void check_and_throw(bool condition, const std::string& message) const;
        static constexpr auto ACCOUNT_ALREADY_OPEN{ "Account already open." };
        static constexpr auto ACCOUNT_NOT_OPEN{ "Account is not open." };
        static constexpr auto ZERO_OR_NEGATIVE_AMOUNT{ "Amount must be > 0.0." };
        static constexpr auto INSUFFICIENT_FUNDS{ "Withdraw more than balance." };
        mutable std::mutex _m{};
        std::optional<AccountState> _state{};
        double _balance{ 0 };

    };  // class Bankaccount
}  // namespace Bankaccount
