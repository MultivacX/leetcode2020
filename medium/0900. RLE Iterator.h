// 900. RLE Iterator

// Runtime: 8 ms, faster than 71.11% of C++ online submissions for RLE Iterator.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for RLE Iterator.

class RLEIterator {
public:
    RLEIterator(vector<int>& A) : _A(A) {
        if (_A.size() >= 2) {
            _index = 0;
            _used = 0;
        }
    }
    
    int next(int n) {
        if (_A.size() < 2) return -1;
        
        while (n > 0 && _index + 1 < _A.size()) {
            int count = _A[_index];
            if (count == 0 || count == _used) {
                _index += 2; 
                _used = 0;
                continue;
            }
            
            int remains = count - _used;
            if (remains >= n) {
                _used += n;
                return _A[_index + 1];
            } else {
                n -= remains;
                _index += 2; 
                _used = 0;
            }
        }
        return -1;
    }
    
    vector<int>& _A;
    int _index{0};
    int _used{0};
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */