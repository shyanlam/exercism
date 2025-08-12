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
        static constexpr auto INVALID_OP{ "Invalid Operation." };
        static constexpr auto INVALID_AMOUNT{ "Invalid amount." };
        mutable std::mutex _m{};
        std::optional<AccountState> _state{};
        double _balance{ 0 };

    };  // class Bankaccount
}  // namespace Bankaccount
