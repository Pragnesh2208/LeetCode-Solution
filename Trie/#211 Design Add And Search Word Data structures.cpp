/** Optimal Solution Design add and Search Word Data Structure
 * Time Complexity for Add is O(N) and Search is O( N * 26)
 * Space Complexity is O(N * 26) and Search is O(1)
 *  
 */

struct Trie{
    Trie * link[26] = {NULL};
    bool isEnd = false;
};
class WordDictionary {
    private:
    Trie * trie = new Trie();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie * obj = trie;
        int n = word.length();
        for(int i = 0 ; i < n ;i++) {
            int ch = word[i] - 'a';
            if(obj -> link[ch] == NULL) {
                Trie * newObj = new Trie();
                obj -> link[word[i] - 'a'] = newObj;
            }
            obj = obj -> link[word[i] - 'a'];
        }
        obj -> isEnd = true;
    }

    bool find(string word , int index , Trie * obj) {
        if(word.length() == index) return obj -> isEnd;

        if(word[index] == '.') {
            for(int i = 0 ; i < 26 ; i++) {
                if(obj -> link[i] != NULL && find(word , index + 1 , obj -> link[i])) return true;
            }
            return false;
        } else {
            int ch = word[index] - 'a';
            if(obj -> link[ch] != NULL) {
                return find(word , index + 1 , obj -> link[ch]);
            } else
            return false;
        }
    }

    bool search(string word) {
        Trie * obj = trie;
        return find(word ,0 , obj);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */