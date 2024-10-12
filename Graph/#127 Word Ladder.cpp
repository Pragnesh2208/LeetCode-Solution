/*****************************Optimal solution of Word Ladder******************************/
/****************************Time Complexity = O( N * M ^ 2) ***********/
/***************************Space Complexity = O(N) ******************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        map<string, vector<string>> mp;
        int n = wordList.size();
        for (string word : wordList) {
            int len = word.size();
            for (int i = 0; i < len; i++) {
                string newString = word.substr(0, i) + "*" + word.substr(i + 1);
                mp[newString].push_back(word);
            }
        }

        map<string, int> visited;
        queue<string> que;
        que.push(beginWord);
        int cnt = 0;
        while (!que.empty()) {
            int sz = que.size();
            cnt++;
            while (sz--) {
                string word = que.front();
                que.pop();
                int len = word.size();
                for (int i = 0; i < len; i++) {
                    string newWord =
                        word.substr(0, i) + "*" + word.substr(i + 1);
                    if (visited[newWord] == 0 && mp[newWord].size() > 0) {
                        visited[newWord]++;
                        for (string str : mp[newWord]) {
                            que.push(str);
                            if(str == endWord) return cnt+ 1;
                        }
                    }
                }
            }
        }

        return 0;
    }
};