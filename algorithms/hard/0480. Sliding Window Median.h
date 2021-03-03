// 480. Sliding Window Median

// Runtime: 160 ms, faster than 18.78% of C++ online submissions for Sliding Window Median.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Sliding Window Median.

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        vector<int> w;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                w.push_back(nums[i]);
                if (i == k - 1) {
                    sort(w.begin(), w.end());
                    ans.push_back(k % 2 ? w[k / 2] : (w[k / 2 - 1] / 2.0 + w[k / 2] / 2.0));
                }
            } else {
                w.erase(lower_bound(w.begin(), w.end(), nums[i - k]));
                w.insert(lower_bound(w.begin(), w.end(), nums[i]), nums[i]);
                ans.push_back(k % 2 ? w[k / 2] : (w[k / 2 - 1] / 2.0 + w[k / 2] / 2.0));
            }
        }
        return ans;
    }
};


// Runtime: 52 ms, faster than 70.61% of C++ online submissions for Sliding Window Median.
// Memory Usage: 16.4 MB, less than 38.82% of C++ online submissions for Sliding Window Median.
    
class Solution {
    bool remove(map<int, int>& m, int& cnt, int v) {
        if (0 == m.count(v)) return false;
        --cnt;
        if (--m[v] == 0)
            m.erase(v);
        return true;
    }
    
    void add(map<int, int>& l, map<int, int>& r, int& ln, int& rn, int v) {
        if (l.empty() || v <= l.crbegin()->first) ++l[v], ++ln;
        else ++r[v], ++rn;
    }
    
    void update(map<int, int>& l, map<int, int>& r, int& ln, int& rn, int offset, vector<double>& ans) {
        while (ln < rn + offset) {
            ++ln; --rn;
            auto it = r.begin();
            ++l[it->first];
            if (--(it->second) == 0)
                r.erase(it->first);
        }
        while (ln > rn + offset) {
            --ln; ++rn;
            auto it = l.rbegin();
            ++r[it->first];
            if (--(it->second) == 0)
                l.erase(it->first);
        }
        
        if (offset == 1) ans.push_back(l.rbegin()->first);
        else ans.push_back(((double)l.rbegin()->first + (double)r.begin()->first) * 0.5);
    }
    
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k == 1) {
            vector<double> ans;
            for (int i : nums) ans.push_back(i);
            return ans;
        } else if (k == n) {
            nth_element(begin(nums), begin(nums) + n / 2, end(nums));
            if (n & 1) return {(double)nums[n / 2]};
            nth_element(begin(nums), begin(nums) + n / 2 - 1, end(nums));
            return {((double)nums[n / 2 - 1] + (double)nums[n / 2]) * 0.5};
        } else {
            const int offset = k & 1;
            vector<double> ans;
            int ln = 0, rn = 0;
            map<int, int> l, r;
            // [min_l, max_l] <= [min_r, max_r]
            for (int i = 0; i < n; ++i) {
                int v = nums[i];
                if (i < k) {
                    ++l[v];
                    ++ln;
                } else {
                    int p = nums[i - k];
                    if (p != v) {
                        if (!remove(l, ln, p))
                            remove(r, rn, p);
                        add(l, r, ln, rn, v);
                    }
                }
                
                if (ln + rn == k) 
                    update(l, r, ln, rn, offset, ans);
            }
            return ans;
        }
    }
};