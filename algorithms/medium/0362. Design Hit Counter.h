// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/

// Runtime: 4 ms, faster than 48.25% of C++ online submissions for Design Hit Counter.
// Memory Usage: 7.8 MB, less than 33.33% of C++ online submissions for Design Hit Counter.
    
class HitCounter {
    unordered_map<int, int> m;
    
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++m[timestamp];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int hits = 0;
        for (int t = 0; t < 5 * 60 && timestamp - t > 0; ++t) {
            auto it = m.find(timestamp - t);
            if (it != m.end()) hits += it->second;
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */