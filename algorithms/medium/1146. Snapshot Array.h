// 1146. Snapshot Array

// Runtime: 472 ms, faster than 32.84% of C++ online submissions for Snapshot Array.
// Memory Usage: 103.6 MB, less than 100.00% of C++ online submissions for Snapshot Array.

class SnapshotArray {
    int snap_id{0};
    vector<map<int, int>> snaps;
    
public:
    SnapshotArray(int length) : snaps(length) {
        for (int i = 0; i < length; ++i)
            snaps[i][snap_id] = 0;
    }
    
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        if (it == snaps[index].begin()) return 0;
        --it;
        return it->second;
    }
};

// Runtime: 472 ms, faster than 32.84% of C++ online submissions for Snapshot Array.
// Memory Usage: 97.1 MB, less than 100.00% of C++ online submissions for Snapshot Array.

class SnapshotArray {
    int snap_id{0};
    unordered_map<int, unordered_map<int, int>> snaps;
    unordered_map<int, int> cur_array;
    const int len;
    
public:
    SnapshotArray(int length) : len(length) {
        
    }
    
    void set(int index, int val) {
        cur_array[index] = val;
    }
    
    int snap() {
        snaps.emplace(snap_id, cur_array);
        cur_array.clear();
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if (snaps.count(snap_id)) {
            while (snap_id >= 0) {
                if (snaps[snap_id].count(index))
                    return snaps[snap_id][index];
                --snap_id;
            }
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */