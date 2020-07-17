// 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/

// Runtime: 16 ms, faster than 30.77% of C++ online submissions for Reveal Cards In Increasing Order.
// Memory Usage: 8.6 MB, less than 49.74% of C++ online submissions for Reveal Cards In Increasing Order.

// Time Complexity: O(N * log(N)).
// Space Complexity: O(N).

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int N = deck.size();
        queue<int> q;
        for (int i = 0; i < N; ++i) 
            q.push(i);
        
        vector<int> idx;
        while (!q.empty()) {
            // reveal
            idx.push_back(q.front());
            q.pop();
            
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        vector<int> ans(N);
        sort(begin(deck), end(deck));
        for (int i = 0; i < N; ++i)
            ans[idx[i]] = deck[i];
        return ans;
    }
};