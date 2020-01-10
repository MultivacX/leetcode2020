// 752. Open the Lock

// Runtime: 52 ms, faster than 91.03% of C++ online submissions for Open the Lock.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Open the Lock.

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") 
            return 0;
        
        unordered_set<string> d(deadends.begin(), deadends.end());
        
        unordered_set<string> front, back, *pf, *pb, visited;
        nextSequence(d, visited, "0000", front);
        back.insert(target);
        
        int step = 1;
        while (!front.empty() && !back.empty()) {
            if (front.size() <= back.size()) {
                pf = &front;
                pb = &back;
            } else {
                pf = &back;
                pb = &front;
            }
            
            unordered_set<string> tmp;
            for (const string& s : *pf) {
                if (pb->count(s)) return step;
                nextSequence(d, visited, s, tmp);
            }
            ++step;
            
            pf->swap(tmp);
        }
        
        return -1;
    }
    
    void nextSequence(unordered_set<string>& deadends, 
                      unordered_set<string>& visited, 
                      string start,
                      unordered_set<string>& ns) {
        if (deadends.count(start) || visited.count(start)) 
            return;
        
        visited.insert(start);
        
        for (int i = 0; i < 4; ++i) {
            string l(turn(start, i, -1));
            if (deadends.count(l) == 0 && visited.count(l) == 0) 
                ns.insert(l);
            
            string r(turn(start, i, 1));
            if (deadends.count(r) == 0 && visited.count(r) == 0) 
                ns.insert(r);
        }
    }
    
    string turn(string s, int i, int move) {
        s[i] += move;
        if (s[i] > '9') s[i] = '0';
        else if (s[i] < '0') s[i] = '9';
        return s;
    }
};