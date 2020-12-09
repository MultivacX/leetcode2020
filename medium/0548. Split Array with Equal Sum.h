// 548. Split Array with Equal Sum
// https://leetcode.com/problems/split-array-with-equal-sum/

// Runtime: 512 ms, faster than 29.79% of C++ online submissions for Split Array with Equal Sum.
// Memory Usage: 12.7 MB, less than 15.60% of C++ online submissions for Split Array with Equal Sum.
    
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ps(N, 0);
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ps[i] = sum;
        }
        
        // [0,i-1] i [i+1,j-1] j [j+1,k-1] k [k+1,N-1]
        
        //   [0,i-1]  :  sum == ps[i-1]
        //         i  : 
        // [i+1,j-1]  :  sum == ps[j-1] - ps[i]
        //         j
        // [j+1,k-1]  :  sum == ps[k-1] - ps[j]
        //         k
        // [k+1,N-1]  :  sum == ps[N-1] - ps[k]
        
        // j = [i+2, N-4]
        // k = [j+2, N-2]
        for (int j = 2; j <= N - 4; ++j) {
            unordered_set<int> sums;
            for (int i = 1; i + 1 < j; ++i) {
                int sum1 = ps[i - 1];
                int sum2 = ps[j - 1] - ps[i];
                if (sum1 == sum2) sums.insert(sum1);
            }
            
            for (int k = j + 2; k <= N - 2; ++k) {
                int sum3 = ps[k - 1] - ps[j];
                int sum4 = ps[N - 1] - ps[k];
                if (sum3 != sum4 || sums.count(sum3) == 0) 
                    continue;
                return true;
            }
        }
        return false;
    }
};

// TLE 111 / 120 test cases passed.
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ps(N, 0);
        unordered_map<int, vector<int>> m;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ps[i] = sum;
            m[sum].push_back(i);
            // cout << i << ":" << sum << ", ";
        }
        
        //   [0,i-1]  :  sum == ps[i-1]
        //         i  : 
        // [i+1,j-1]  :  sum == ps[j-1] - ps[i]
        //         j
        // [j+1,k-1]  :  sum == ps[k-1] - ps[j]
        //         k
        // [k+1,N-1]  :  sum == ps[N-1] - ps[k]
        
        for (int i = 1; i <= N - 6; ++i) {
            // j = [i+2, N-4]
            // k = [j+2, N-2]
            
            int sum = ps[i-1];
            // cout << endl << sum << "[" << i << "]";  
            
            int ps_j_1 = sum + ps[i];
            if (m.count(ps_j_1) == 0) continue;
            const auto& idxes_j_1 = m[ps_j_1];
            auto it_j_1 = lower_bound(begin(idxes_j_1), end(idxes_j_1), i+1); 
            for (; it_j_1 != end(idxes_j_1) && *it_j_1 < N-4; ++it_j_1) {
                int j = *it_j_1 + 1;
                // cout << "[" << j << "]";
                
                int ps_k_1 = sum + ps[j];
                if (m.count(ps_k_1) == 0) continue;
                const auto& idxes_k_1 = m[ps_k_1];
                auto it_k_1 = lower_bound(begin(idxes_k_1), end(idxes_k_1), j+1); 
                for (; it_k_1 != end(idxes_k_1) && *it_k_1 < N-2; ++it_k_1) {
                    int k = *it_k_1 + 1;
                    // cout << "[" << k << "]"; 
            
                    int last = ps[N-1] - ps[k];
                    if (last == sum) return true;
                }
            }
        }
        return false;
    }
};

// WA 118 / 120 test cases passed.
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ps(N, 0);
        unordered_map<int, vector<int>> m;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ps[i] = sum;
            m[sum].push_back(i);
        }
        
        //   [0,i-1]  :  sum == ps[i-1]
        //         i  : 
        // [i+1,j-1]  :  sum == ps[j-1] - ps[i]
        //         j
        // [j+1,k-1]  :  sum == ps[k-1] - ps[j]
        //         k
        // [k+1,N-1]  :  sum == ps[N-1] - ps[k]
        
        for (int i = 1; i <= N - 6; ++i) {
            // j = [i+2, N-4]
            // k = [j+2, N-2]
            
            int sum = ps[i-1];
            
            int ps_j_1 = sum + ps[i];
            if (m.count(ps_j_1) == 0) continue;
            const auto& idxes_j_1 = m[ps_j_1];
            auto it_j_1 = lower_bound(begin(idxes_j_1), end(idxes_j_1), i+1); 
            if (it_j_1 == end(idxes_j_1)) continue;
            int j = *it_j_1 + 1;
            if (j > N-4) continue;
            
            int ps_k_1 = sum + ps[j];
            if (m.count(ps_k_1) == 0) continue;
            const auto& idxes_k_1 = m[ps_k_1];
            auto it_k_1 = lower_bound(begin(idxes_k_1), end(idxes_k_1), j+1); 
            if (it_k_1 == end(idxes_k_1)) continue;
            int k = *it_k_1 + 1;
            if (k > N-2) continue;
            
            int last = ps[N-1] - ps[k];
            if (last == sum) return true;
        }
        return false;
    }
};