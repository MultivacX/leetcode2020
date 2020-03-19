// 355. Design Twitter

// Runtime: 132 ms, faster than 9.21% of C++ online submissions for Design Twitter.
// Memory Usage: 19.9 MB, less than 100.00% of C++ online submissions for Design Twitter.

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back({tweetId, userId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        for (int i = (int)tweets.size() - 1; i >= 0 && feeds.size() < 10; --i) {
            // int tweetId = tweets[i].first;
            int followeeId = tweets[i].second;
            if (userId == followeeId || (followees.count(userId) && followees[userId].count(followeeId)))
                feeds.push_back(tweets[i].first);
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
    
    // {tweetId, userId}
    vector<pair<int, int>> tweets;
    // {followerId, {followeeId}}
    unordered_map<int, unordered_set<int>> followees;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */