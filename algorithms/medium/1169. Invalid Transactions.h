// 1169. Invalid Transactions

// Runtime: 92 ms, faster than 53.13% of C++ online submissions for Invalid Transactions.
// Memory Usage: 16.9 MB, less than 100.00% of C++ online submissions for Invalid Transactions.

class Solution {
    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
        int idx;
        
        void print() { printf("name:%s, time:%d, amount:%d, city:%s, %d\n", name.c_str(), time, amount, city.c_str(), idx); }
    };
    
    Transaction create(const string& transaction, int idx) {
        Transaction t;
        t.idx = idx;
        
        const int N = transaction.length();
        
        int begin = 0;
        auto comma = transaction.find(',', begin);
        t.name = transaction.substr(begin, comma - begin);
        
        begin = comma + 1;
        comma = transaction.find(',', begin);
        t.time = stoi(transaction.substr(begin, comma - begin));
        
        begin = comma + 1;
        comma = transaction.find(',', begin);
        t.amount = stoi(transaction.substr(begin, comma - begin));
        
        begin = comma + 1;
        comma = transaction.find(',', begin);
        t.city = transaction.substr(begin, comma - begin);
        
        return t;
    }
    
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_set<int> invalidIdx;
        // name -> city -> {time, amount, idx}
        unordered_map<string, unordered_map<string, set<vector<int>>>> m;
        for (int i = 0; i < transactions.size(); ++i) {
            auto t = create(transactions[i], i);
            // t.print();
            m[t.name][t.city].insert({t.time, t.amount, t.idx});
        }
        vector<int> time_amount_idx{0, 0, 0};
        for (const auto& data : m) {
            // data.first: name
            // data.second: {{city, {time, amount, idx}}}
            for (auto i = data.second.begin(); i != data.second.end(); ++i) {
                // i->first: city
                // check different city
                auto j = i;
                for (++j; j != data.second.end(); ++j) {
                    // j->first: city
                    // check time
                    for (const auto& i_ : i->second) {
                        time_amount_idx[0] = i_[0] - 60;
                        auto it = j->second.upper_bound(time_amount_idx);
                        while (it != j->second.end() && abs((*it)[0] - i_[0]) <= 60) {
                            invalidIdx.emplace(i_[2]);
                            invalidIdx.emplace((*it)[2]);
                            // cout << "b:" << (*it)[2] << endl;
                            ++it;
                        }
                    }
                }
                // check amount
                for (const auto& tai : i->second) {
                    if (tai[1] <= 1000) continue;
                    invalidIdx.emplace(tai[2]);
                    // cout << "c:" << tai[2] << endl;
                }
            }
        }
        vector<string> ans;
        for (int idx : invalidIdx) ans.push_back(transactions[idx]);
        return ans;
    }
};