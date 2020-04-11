// 433. Minimum Genetic Mutation

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Genetic Mutation.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Minimum Genetic Mutation.

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (find(bank.begin(), bank.end(), end) == bank.end()) return -1;
        
        unordered_map<unsigned, unordered_set<unsigned>> m;
        unsigned us = gen_mutations(start, m);
        unsigned ue = 0;
        for (string& b : bank) {
            unsigned ui = gen_mutations(b, m);   
            if (end == b) ue = ui;
        }
        
        int count = 0;
        unordered_set<unsigned> s1{us};
        unordered_set<unsigned> s2{ue};
        unordered_set<unsigned> visited;
        bool found = false;
        while (!s1.empty() && !s2.empty()) {
            unordered_set<unsigned> t1;
            for (int i : s1) {
                if (s2.count(i)) {
                    found = true;
                    break;
                }
                
                if (visited.count(i)) continue;
                visited.insert(i);
                
                for (int j : m[i]) {
                    if (visited.count(j)) continue;
                    t1.insert(j);
                }
            }
            
            if (found) break;
            
            unordered_set<unsigned> t2;
            for (int i : s2) {
                if (visited.count(i)) continue;
                visited.insert(i);
                
                for (int j : m[i]) {
                    if (visited.count(j)) continue;
                    t2.insert(j);
                }
            }
            
            s1 = t1;
            s2 = t2;
            if (s1.size() > s2.size()) swap(s1, s2);
            
            count += 1;
        }
        return found ? count : -1;
    }
    
    int gen_mutations(string& s, unordered_map<unsigned, unordered_set<unsigned>>& m) {
        unsigned x = 0;
        for (int i = 0; i < 8; ++i) {
            switch (s[i]) {
                case 'A': x |= 0b0001 << (i * 4); break;
                case 'C': x |= 0b0010 << (i * 4); break;
                case 'G': x |= 0b0100 << (i * 4); break;
                case 'T': x |= 0b1000 << (i * 4); break;
            }
        }
        
        static const vector<unsigned> masks{
            0b11111111111111111111111111110000,
            0b11111111111111111111111100001111,
            0b11111111111111111111000011111111,
            0b11111111111111110000111111111111,
            0b11111111111100001111111111111111,
            0b11111111000011111111111111111111,
            0b11110000111111111111111111111111,
            0b00001111111111111111111111111111,
        };
        for (int i = 0; i < 8; ++i) {
            unsigned y = x & masks[i];
            m[x].insert(y);
            m[y].insert(x);
        }
        
        return x;
    }
};