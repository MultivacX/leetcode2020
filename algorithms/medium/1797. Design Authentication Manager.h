// 1797. Design Authentication Manager
// https://leetcode.com/problems/design-authentication-manager/

// Runtime: 68 ms, faster than 94.68% of C++ online submissions for Design Authentication Manager.
// Memory Usage: 32.2 MB, less than 6.49% of C++ online submissions for Design Authentication Manager.
    
class AuthenticationManager {
    struct token {
        token(const string& id, int ct) : tokenId(id), currentTime(ct) {}
        string tokenId;
        int currentTime;
    };
    
    int ttl;
    list<token> tokens;
    unordered_map<string, list<token>::iterator> m;
    
public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        m.emplace(tokenId, tokens.emplace(tokens.end(), tokenId, currentTime));
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = m.find(tokenId);
        if (it == end(m)) return;
        
        int expire = it->second->currentTime + ttl;
        tokens.erase(it->second);
        m.erase(it);
        if (expire > currentTime) 
            m.emplace(tokenId, tokens.emplace(tokens.end(), tokenId, currentTime));
    }
    
    int countUnexpiredTokens(int currentTime) {
        while (!tokens.empty() && tokens.front().currentTime + ttl <= currentTime) {
            m.erase(tokens.front().tokenId);
            tokens.pop_front();
        }
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */