// 460. LFU Cache

struct KeyNode {
    int key;
    KeyNode *prev, *next;
    
    KeyNode(int k) : key(k), prev(nullptr), next(nullptr) {}
};

struct FrqNode {
    int frq;
    KeyNode head, tail; 
    FrqNode *prev, *next;
    
    FrqNode(int f) : frq(f), head(-1), tail(-1), prev(nullptr), next(nullptr) {}

    
};

class LFUCache {
public:
    /*void print() {
        auto li = head;
        while (li) {
            cout << li->frq << ": ";
            auto kv = li->head;
            while (kv) {
                printf("(%d,%d,%d) ", kv->key, kv->val, kv->frq);
                kv = kv->next;
            }
            cout << endl;
            li = li->next;
        }
    }*/

    /* struct Data {
        Data(int k, int v) : key(k), val(v) {}

        int key{-1};
        int val{-1};
        int frq{0};

        list<int>* pList{nullptr};
        int* pKey{nullptr};
    };
    
    unordered_map<int, Data> key2data;
    unordered_map<int, list<int>*> frq2list;

    list<list<int>> l; */

    int cap;
    
    LFUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        /* Data* pData = visit(key);
        return pData ? pData->val : -1; */
        return -1;
    }
    
    void put(int key, int value) {
        /* Data* pData = visit(key);
        if (pData) {
            pData->val = value;
        } else {
            key2data.insert({key, Data(key, value)});
            pData = &key2data[key];
        } */
    }

    /* Data* visit(int key) {
        if (!key2data.count(key)) return nullptr;

        auto& data = key2data[key];

        data.pList->remove(*data.pKey);
        if (data.pList->empty()) l.remove(*data.pList);
        data.pList = nullptr;
        data.pKey = nullptr;

        ++data.frq;
        data.pList = 

        return &data;
    } */
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */