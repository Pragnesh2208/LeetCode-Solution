class Trie {
    private:
    Trie * link[26] = { NULL};
    bool isEnd = false;
public:
    Trie() {
        Trie * link[26] = {NULL};
        bool isEnd = false;
    }
    
    void insert(string word) {
         Trie* newObj1 = this;
        
        int n = word.length();
        for(int i = 0 ; i < n ; i++) {
            if(newObj1->link[word[i]-'a'] == NULL) {
                 Trie* newObj2 = new Trie();
                newObj1->link[word[i] - 'a'] = newObj2;
            }
            
              newObj1 =  newObj1->link[word[i] - 'a'];
            
        }
        newObj1 -> isEnd = true;
    }
    
    bool search(string word) {
        Trie* newObj1 = this;
        int i = 0 , n = word.length();
        while(i < n ){
            if(newObj1 -> link[word[i]-'a'] == NULL) {
                return false;
            }
            
            newObj1 = newObj1 -> link[word[i]-'a'];
            
            if(i == n-1 && newObj1->isEnd == false){
                return false;
            }
            i++;
            
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Trie* newObj1 = this;
         int i = 0 , n = prefix.length();
        while(i < n ){
            if(newObj1 -> link[prefix[i]-'a'] == NULL) {
                return false;
            }
            
            newObj1 = newObj1 -> link[prefix[i]-'a'];
            i++;
        }
    
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */