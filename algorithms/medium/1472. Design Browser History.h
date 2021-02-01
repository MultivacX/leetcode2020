// 1472. Design Browser History
// https://leetcode.com/problems/design-browser-history/

// Runtime: 192 ms, faster than 84.86% of C++ online submissions for Design Browser History.
// Memory Usage: 54.7 MB, less than 9.93% of C++ online submissions for Design Browser History.

class BrowserHistory {
    vector<string> pages;
    int i = 0;
    
public:
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
    }
    
    void visit(string url) {
        ++i;
        if (i >= pages.size()) {
            pages.push_back(url);
        } else {
            pages[i] = url;
            pages.resize(i + 1);
        }
    }
    
    string back(int steps) {
        i = max(0, i - steps);
        return pages[i];
    }
    
    string forward(int steps) {
        i = min((int)pages.size() - 1, i + steps);
        return pages[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */