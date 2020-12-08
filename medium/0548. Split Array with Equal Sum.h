// 548. Split Array with Equal Sum

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