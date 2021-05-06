// 1172. Dinner Plate Stacks
// https://leetcode.com/problems/dinner-plate-stacks/

// Runtime: 484 ms, faster than 67.57% of C++ online submissions for Dinner Plate Stacks.
// Memory Usage: 219.1 MB, less than 50.00% of C++ online submissions for Dinner Plate Stacks.
    
class DinnerPlates {
    const int n;
    vector<vector<int>> ss;
    set<int> availables;
    // int left = 0;
    
public:
    DinnerPlates(int capacity) : n (capacity) {
        
    }
    
    void push(int val) {
        int i = 0;
        if (availables.empty()) {
            i = ss.size();
            ss.push_back({val});
        } else {
            i = *availables.cbegin();
            ss[i].push_back(val);
        }
        if (ss[i].size() == n) availables.erase(i);
        else availables.insert(i);
    }
    
    int pop() {
        while (!ss.empty() && ss.back().empty()) {
            ss.pop_back();
            availables.erase(ss.size());
        }
        if (ss.empty() || ss.back().empty()) return -1;
        int ans = ss.back().back();
        ss.back().pop_back();
        availables.insert(ss.size() - 1);
        return ans;
    }
    
    int popAtStack(int index) {
        if (index >= ss.size() || ss[index].empty()) return -1;
        int ans = ss[index].back();
        ss[index].pop_back();
        availables.insert(index);
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */