// 2043. Simple Bank System
// https://leetcode.com/problems/simple-bank-system/

// Runtime: 289 ms, faster than 70.06% of C++ online submissions for Simple Bank System.
// Memory Usage: 113.9 MB, less than 94.48% of C++ online submissions for Simple Bank System.

class Bank
{
    vector<long long> &_balance;

public:
    Bank(vector<long long> &balance) : _balance(balance)
    {
    }

    bool transfer(int account1, int account2, long long money)
    {
        const int n = _balance.size();
        --account1, --account2;
        if (account1 < 0 || account1 >= n || account2 < 0 || account2 >= n || money < 0 || _balance[account1] < money)
            return false;

        _balance[account1] -= money;
        _balance[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        const int n = _balance.size();
        --account;
        if (account < 0 || account >= n || money < 0)
            return false;

        _balance[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        const int n = _balance.size();
        --account;
        if (account < 0 || account >= n || money < 0 || _balance[account] < money)
            return false;

        _balance[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */