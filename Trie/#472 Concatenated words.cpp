/**
 * Optimal approach to Solve Concatenated words
 * Time Complexity = O(N * L ^2)
 * here we have consider hashing operation to be O(1)
 * Space Complexity  = O(N)
 */

class Solution {
private:
    bool memo(string word, unordered_set<string>& set, unordered_map<string , bool>& visited) {
        if(visited.find(word) != visited.end()) return visited[word];
        int n = word.length();
        for (int i = 0; i < n; i++) {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);
            if ((set.find(prefix) != set.end() &&
                 set.find(suffix) != set.end()) ||
                (set.find(prefix) != set.end() && memo(suffix, set , visited))) {
                return visited[word] = true;
            }
        }
        return visited[word] = false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        unordered_map<string , bool>visited;
        vector<string> ans;
        for (string word : words) {
            if (memo(word, set , visited))
                {
                    ans.push_back(word);
                } 
        }
        return ans;
    }
};