// 1625. Lexicographically Smallest String After Applying Operations
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution {
    void add_a(string& s, int a, vector<vector<int>>& nums) {
        const int N = s.length();
        for (int k = 1, idx = -1; k < N; k += 2) {
            int num = s[k] - '0';
            if (k == 1) {
                idx = 0;
                int v = nums[num][0];
                for (int j = 1; j < 10; ++j) {
                    if (v > nums[num][j]) {
                        idx = j;
                        v = nums[num][j];
                    }
                }
            } 
            s[k] = nums[num][idx] + '0';
        }    
    }
    
public:
    string findLexSmallestString(string s, int a, int b) {
        vector<vector<int>> nums(10, vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                nums[i][j] = (i + j * a) % 10;
            }
        }
        
        set<string> strs;
        const int N = s.length();
        int i = 0;
        do {
            cout << s << ": ";
            add_a(s, a, nums);
            strs.insert(s);
            cout << s << "   ";
            
            reverse(begin(s), begin(s) + N - b);
            reverse(begin(s) + N - b, end(s));
            reverse(begin(s), end(s));
            cout << s << endl;
            
            i = (i + b) % N;
        } while (i);
        
        cout << s << ": ";
        add_a(s, a, nums);
        strs.insert(s);
        cout << s << endl;
        
        return *strs.begin();
    }
};