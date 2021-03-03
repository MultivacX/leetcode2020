// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/

// Runtime: 104 ms, faster than 78.62% of C++ online submissions for Logger Rate Limiter.
// Memory Usage: 33 MB, less than 44.47% of C++ online submissions for Logger Rate Limiter.
    
class Logger {
    unordered_map<string, int> m;
    
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = m.find(message);
        if (it == m.end()) {
            m.insert({message, timestamp});
            return true;
        }
        if (timestamp - it->second < 10) {
            return false;
        }
        it->second = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */


class Logger {
    unordered_map<string, int> next_timestamps;
    
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = next_timestamps.find(message);
        if (it == next_timestamps.end() || it->second <= timestamp) {
            next_timestamps[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};