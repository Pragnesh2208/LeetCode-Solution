
/**
 * Below is code for Ladder II give TLE
 * Time Complexity = O(N * M)
 * Space Complexity = O(N * M)
 */
class Solution {
    private:
    vector<vector<string>> ans;
    vector<string>path;
    void dfs(int depth, unordered_set<string> st, string& endWord , unordered_map<string, vector<string>> &mp) {
        string word = path.back();

        if (word == endWord) {
            ans.push_back(path);
            return;
        }
        if(depth == 0) return;
        int len = word.length();
        for (string newWord : mp[word]) {
            if (st.find(newWord) != st.end()) {
                path.push_back(newWord);
                dfs(depth - 1  , st , endWord , mp);
                path.pop_back();
            }
        }
        if (st.find(word) != st.end())
            st.erase(st.find(word));
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, bool> visited;
        st.insert(beginWord);
        for (const string& word : st) {
            int len = word.length();
            for (int i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string ch;
                    ch.push_back(c);
                    string newWord =
                        word.substr(0, i) + ch + word.substr(i + 1);
                    if (st.find(newWord) != st.end() && word != newWord) {
                        mp[word].push_back(newWord);
                    }
                }
            }
        }

        queue<string> que;
        que.push(beginWord);
        int cnt = 0;
        ans = {};
        while (!que.empty()) {
            int sz = que.size();
            bool flag = false;
            cnt++;
            while (sz--) {
                string word = que.front();
                que.pop();
                int len = word.length();
                bool flag1 = false;
                for (string newWord : mp[word]) {
                    if (!visited[newWord]) {
                        visited[newWord] = true;
                        if (newWord == endWord) {
                            cnt++;
                            flag = true;
                            flag1 = true;
                            break;
                        }
                        que.push(newWord);
                    }
                }
                if (flag1)
                    break;
            }
            if (flag)
                break;
        }
        path = {};
        path.push_back(endWord);
        dfs(cnt - 1 , st , beginWord, mp );

            return ans;
    }
};