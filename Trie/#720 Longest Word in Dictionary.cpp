/**
 * Optimal Solution to Solve Longest Word in Dictionary
 * Time Complexity = O(N)
 * Space Complexity = O(N)
 */
struct Trie {
    Trie* link[26] = {NULL};
    bool isEnd = false;
};
class Solution {
private:
    Trie* root = new Trie();

    void insert(string word) {
        Trie* obj = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (obj->link[index] == NULL) {
                Trie* newObj = new Trie();
                obj->link[index] = newObj;
            }
            obj = obj->link[index];
        }
        obj->isEnd = true;
    }

    string search(Trie* obj) {

        if (obj == NULL)
            return "";
        string maxSt = "";
        for (int i = 0; i < 26; i++) {

            if (obj->link[i] != NULL && obj -> link[i] -> isEnd) {
                string temp;

                char ch = char(i + 'a');
                temp.push_back(ch);
                temp += (search(obj->link[i]));
                if (temp.length() > maxSt.length())
                    maxSt = temp;
            }
        }
        return maxSt;
    }

public:
    string longestWord(vector<string>& words) {

        for (string word : words)
            insert(word);

        return search(root);
    }
};