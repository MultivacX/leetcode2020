// 1348. Tweet Counts Per Frequency
// https://leetcode.com/problems/tweet-counts-per-frequency/

// Runtime: 140 ms, faster than 64.29% of C++ online submissions for Tweet Counts Per Frequency.
// Memory Usage: 38.5 MB, less than 95.24% of C++ online submissions for Tweet Counts Per Frequency.
    
class TweetCounts {
    unordered_map<string, vector<int>> tweets;
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int step = 60;
        if (freq == "hour") step *= 60;
        else if (freq == "day") step *= 60 * 24;
        
        vector<int> ans((endTime - startTime) / step + 1, 0);
        for (int t : tweets[tweetName]) {
            if (startTime <= t && t <= endTime) {
                ++ans[(t - startTime) / step];
            }
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

// WA 19/21
/*class TweetCounts {
    // unordered_map<string, set<int>> tweets;
    unordered_map<string, vector<int>> tweets;
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        auto& times = tweets[tweetName];
        times.insert(upper_bound(begin(times), end(times), time), time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int step = 60;
        if (freq == "hour") step *= 60;
        else if (freq == "day") step *= 60 * 24;
        
        vector<int> ans;
        auto& times = tweets[tweetName];
        auto l = lower_bound(begin(times), end(times), startTime);
        for (int st = startTime; st <= endTime; st += step) {
            // [st, et)
            int et = st + step;
            
            if (l == end(times) || *l >= et) {
                ans.push_back(0);
                continue;
            }
            
            auto r = lower_bound(l, end(times), et);
            ans.push_back(r - l);
            l = r;
        }
        return ans;
    }
};*/