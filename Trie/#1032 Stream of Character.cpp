/**
 * Optimal Solution to solve stream of character
 * Time Complexity = O(N)
 * Space Complexity = O(N)
 */
struct Trie {
    Trie * link[26];
    bool isEnd = false;
};
class StreamChecker {
    private : Trie * root = new Trie();
    int largestString = 0;
    string curString;
    void insert(string word) {
        Trie * obj = root;
        if(word.length() > largestString) {
            largestString = word.length();
        }
        for(char ch : word) {
            int index = ch - 'a';
            if(obj -> link[index] == NULL) {
                Trie * newObj = new Trie();
                obj -> link[index] = newObj;
            }
            obj = obj -> link[index];
        }
        obj -> isEnd = true;
    }

    bool prefix(string &word) {
         Trie * obj = root;

        for(char ch : word) {
            int index= ch - 'a';
            if(obj -> isEnd) return true;
            if(obj -> link[index] == NULL) return false;
            obj = obj -> link[index];
        }

        return obj -> isEnd;
    }
public:
    StreamChecker(vector<string>& words) {
        for(string word : words){
            reverse(word.begin() , word.end());
            insert(word);}
    }
    
    bool query(char letter) {
        Trie * obj;
        string temp;
        temp.push_back(letter);
        curString = temp + curString;
        if(curString.length() > largestString) curString.pop_back();
        bool ans = prefix(curString);
        return ans;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */