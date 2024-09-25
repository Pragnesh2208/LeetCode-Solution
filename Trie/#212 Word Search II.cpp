/**
 * Optimal solution to find solution for Word Search II
 * Time complexity = O((M * N ) * (4 * 3 ^ L))
 * M = totalRow , N = totalCol , L is max length of word
 * Space Complexity = O(N)
 * N = total words
 * 
 */

int getIndex(char c) { return c - 'a'; }

struct Trie {
    Trie* link[26] = {NULL};
    string word = "";

    void insert(string& word) {
        Trie* root = this;
        for (char ch : word) {
            int index = getIndex(ch);
            if (root->link[index] == NULL) {
                Trie* newObj = new Trie();
                root->link[index] = newObj;
            }
            root = root -> link[index];
        }
        root->word = word;

    }
};
class Solution {
private:
    Trie* root = new Trie();
    set<string> ans;
    void backtrack(int row, int col, vector<vector<char>>& board, Trie* obj) {
        int totalRow = board.size();
        int totalCol = board.back().size();

        if (obj->word != "") {
            ans.insert(obj -> word);
        }

        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, -1, 0, 1};
        char temp = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int verticle = rowOffset[i];
            int horizontal = colOffset[i];
            int newRow = row + horizontal;
            int newCol = col + verticle;
            if (newRow >= 0 && newRow < totalRow && newCol >= 0 &&
                newCol < totalCol && board[newRow][newCol] != '#') {
                int index = getIndex(board[newRow][newCol]);
                
                if (obj->link[index] != NULL) {
                    backtrack(newRow, newCol, board, obj->link[index]);
                }
            }
        }

        board[row][col] = temp;

    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int totalRow = board.size();
        int totalCol = board.back().size();
        ans = {};
        for (string word : words) {
            root->insert(word);
        }

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                int index = getIndex(board[row][col]);
                if (root->link[index] != NULL) {
                    backtrack(row, col, board, root -> link[index]);
                }
            }
        }
        vector<string>an;
        for(auto word : ans) an.push_back(word); 
        return an;
    }
};