#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _nbDeposits++;
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit)
              << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    if (_amount >= withdrawal) {
        _nbWithdrawals++;
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal)
                  << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
}

void Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

#include <ctime> 

void Account::_displayTimestamp() {
    time_t now = time(nullptr); // Utilisez time_t et time() sans std::
    struct tm *ptm = localtime(&now); // Utilisez struct tm et localtime() sans std::

    char buffer[32];
    strftime(buffer, 32, "[%Y%m%d_%H%M%S] ", ptm); // Utilisez strftime sans std::
    std::cout << buffer;
}
