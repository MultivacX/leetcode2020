// 1500. Design a File Sharing System
// https://leetcode.com/problems/design-a-file-sharing-system/

// Runtime: 788 ms, faster than 40.79% of C++ online submissions for Design a File Sharing System.
// Memory Usage: 139.3 MB, less than 40.79% of C++ online submissions for Design a File Sharing System.
    
class FileSharing {
    vector<set<int>> chunks;
    unordered_map<int, unordered_set<int>> users;
    set<int> leavedUsers;
    
public:
    FileSharing(int m) : chunks(m + 1) {
        
    }
    
    int join(vector<int> ownedChunks) {
        int userID = users.size() + leavedUsers.size() + 1;
        if (!leavedUsers.empty()) {
            userID = *leavedUsers.begin();
            leavedUsers.erase(leavedUsers.begin());
        }
        
        users[userID];
        for (int chunkID : ownedChunks) {
            chunks[chunkID].insert(userID);
            users[userID].insert(chunkID);
        }
        return userID;
    }
    
    void leave(int userID) {
        if (users.count(userID) == 0) return;
        
        for (int chunkID : users[userID]) {
            chunks[chunkID].erase(userID);
        }
        users.erase(userID);
        leavedUsers.insert(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> ans(begin(chunks[chunkID]), end(chunks[chunkID]));
        if (!chunks[chunkID].empty()) {
            chunks[chunkID].insert(userID);
            users[userID].insert(chunkID);
            leavedUsers.erase(userID);
        }
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */