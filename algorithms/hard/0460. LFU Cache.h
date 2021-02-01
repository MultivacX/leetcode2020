// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

// Runtime: 156 ms, faster than 92.88% of C++ online submissions for LFU Cache.
// Memory Usage: 43.4 MB, less than 6.27% of C++ online submissions for LFU Cache.

class LFUCache {
    int _capacity;
    int _minfrq;
    
    // {frq, {kvs}}
    unordered_map<int, list<pair<int, int>>> _frqs;
    
    // {key, it2kv}
    unordered_map<int, list<pair<int, int>>::iterator> _datas;
    // {key, frq}
    unordered_map<int, int> _data2frq;
    
    int update(int key, int* newVal = nullptr) {
        auto it2kv = _datas[key];
        int val = newVal ? *newVal : it2kv->second;
        int frq = _data2frq[key];
        
        // add 2 new list
        _frqs[frq + 1].emplace_back(key, val);
        _datas[key] = _frqs[frq + 1].end();
        --_datas[key];
        _data2frq[key] = frq + 1;
        
        // erase from old list
        _frqs[frq].erase(it2kv);
        if (_frqs[frq].empty()) {
            _frqs.erase(frq);
            if (_minfrq == frq) 
                ++_minfrq;
        }
        
        return val;
    }
    
    void tryEvict() {
        if (_datas.size() != _capacity) return;
        
        auto it2kv = _frqs[_minfrq].begin();
        int key = it2kv->first;
        int val = it2kv->second;
        
        _datas.erase(key);
        _data2frq.erase(key);
        _frqs[_minfrq].pop_front();
        if (_frqs[_minfrq].empty())
            _frqs.erase(_minfrq);
    }
    
public:
    LFUCache(int capacity)
    : _capacity(capacity)
    , _minfrq(0) {
        
    }
    
    int get(int key) {
        if (_capacity <= 0 || _datas.count(key) == 0) return -1;
        return update(key);
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) return;
        
        if (_datas.count(key)) {
            update(key, &value);
            return;
        }
        
        tryEvict();
        
        _minfrq = 1;
        _frqs[_minfrq].emplace_back(key, value);
        _datas[key] = _frqs[_minfrq].end();
        --_datas[key];
        _data2frq[key] = _minfrq;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */