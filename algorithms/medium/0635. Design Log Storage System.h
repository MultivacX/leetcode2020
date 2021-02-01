// 635. Design Log Storage System
// https://leetcode.com/problems/design-log-storage-system/

// Runtime: 24 ms, faster than 81.13% of C++ online submissions for Design Log Storage System.
// Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Design Log Storage System.

class LogSystem {
    static unordered_map<string, vector<int>> m;
    map<int64_t, int> logs;
    
    int64_t getKey(const string& timestamp, int t = 0) {
        
        int64_t year = (timestamp[0] - '0') * 1000 + (timestamp[1] - '0') * 100
                       + (timestamp[2] - '0') * 10  + (timestamp[3] - '0');
        
        int64_t month  = (timestamp[5] - '0') * 10  + (timestamp[6] - '0');
        if (t < 0 && t > -2) month = 0;
        else if (t > 0 && t < 2) month = 99;

        int64_t day    = (timestamp[8] - '0') * 10  + (timestamp[9] - '0');
        if (t < 0 && t > -3) day = 0;
        else if (t > 0 && t < 3) day = 99;

        int64_t hour   = (timestamp[11] - '0') * 10 + (timestamp[12] - '0');
        if (t < 0 && t > -4) hour = 0;
        else if (t > 0 && t < 4) hour = 99;

        int64_t minute = (timestamp[14] - '0') * 10 + (timestamp[15] - '0');
        if (t < 0 && t > -5) minute = 0;
        else if (t > 0 && t < 5) minute = 99;

        int64_t second = (timestamp[17] - '0') * 10 + (timestamp[18] - '0');
        if (t < 0 && t > -6) second = 0;
        else if (t > 0 && t < 6) second = 99;
        
        int64_t key = year * 10000000000 + 
                     month * 100000000 +
                       day * 1000000 +
                      hour * 10000 +
                    minute * 100 +
                    second * 1;
        return key;
    }
    
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        logs.insert({getKey(timestamp), id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ans;
        int64_t l = getKey(start, m[granularity][0]);
        int64_t r = getKey(end, m[granularity][1]);
        auto s = logs.lower_bound(l);
        auto e = logs.lower_bound(r + 1);
        for (auto it = s; it != e; ++it)
            ans.push_back(it->second);
        return ans;
    }
};

unordered_map<string, vector<int>> LogSystem::m = {
    {"Year",   {-1, 1}},
    {"Month",  {-2, 2}},
    {"Day",    {-3, 3}},
    {"Hour",   {-4, 4}},
    {"Minute", {-5, 5}},
    {"Second", {-6, 6}},
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */