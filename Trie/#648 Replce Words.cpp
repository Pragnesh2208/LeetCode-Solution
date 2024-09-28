/**
 * Optimal approach to solve Replace Words
 * Time Complexity = O(N)
 * Space Complexity  = O(N)
 */
struct Trie {
    Trie* link[26] ={NULL};
    bool isEnd = false;
};
class Solution {
private
    Trie* root = new Trie();
    void insert(vector<string>&dict) {
        for(string word : dict) {
            Trie * obj = root;

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
    }

    string shortSentence(string &word){
        Trie * obj = root;
        string ansString = "";
        for(char c : word){
            int index = c - 'a';
            if(obj -> link[index] == NULL) return word;
            if(obj -> link[index] != NULL) {
                ansString += c;
                obj = obj -> link[index];
                if(obj -> isEnd) return ansString;
            }
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        insert(dictionary);
        istringstream sStream(sentence);
        string newSentence;
        string word;
        while(getline(sStream , word , ' ')) {
            newSentence += shortSentence(word) + " ";
        }
        newSentence.pop_back();
        return newSentence;
    }
};