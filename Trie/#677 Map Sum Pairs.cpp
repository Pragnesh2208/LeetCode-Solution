/**
 * Optimal approach to Solve Map Sum Pairs
 * Time Complexity = O(NLogN)
 * Space Complexity  = O(N)
 */

struct Trie {
    Trie* link[26] = {NULL};
    bool isEnd = false;
    int count = 0;k
};
 class MapSum {
private:
    Trie* root;
    map<string , int>mp;
public:
    MapSum() { this->root = new Trie(); }
    int search(string key) {
        Trie* obj = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (obj->link[index] == NULL )
                return 0 ;
            obj = obj->link[index];
        }

        return obj -> count;
    }
    void insert(string key, int val) {
        Trie* obj = root;
        int existingKey = mp.find(key) != mp.end() ? mp[key]  : 0;
        mp[key] = val;
        int value = val - existingKey;
        for (char ch : key) {
            int index = ch - 'a';
            if (obj->link[index] == NULL) {
                Trie* newObj = new Trie();
                obj->link[index] = newObj;
            }
            obj -> count+= value;
            obj = obj->link[index];
        }
        obj -> count+= value;
        obj -> isEnd = true;
    }

    int sum(string prefix) { return search(prefix); }
};
