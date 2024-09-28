/**
 * Optimal approach to solve Replace Words
 * Time Complexity = O(N)
 * Space Complexity  = O(N)
 */
struct Trie {
    Trie* link[2] = {NULL};
};
class Solution {
private:
    Trie* root = new Trie();
    void insert(int num) {
        Trie* obj = root;

        for (int bit = 31; bit >= 0; bit--) {
            bool isBitset = (num & (1 << bit));
            if (obj->link[isBitset] == NULL) {
                Trie* newObj = new Trie();
                obj->link[isBitset] = newObj;
            }
            obj = obj->link[isBitset];
        }
    }

    int search(int num) {
        Trie* obj = root;
        int tempNum = 0;
        for (int bit = 31; bit >= 0; bit--) {
            bool isBitset = num & (1 << bit);

            if (obj->link[isBitset] == NULL) {
                isBitset = !isBitset;
            }

            if (isBitset) {
                tempNum |= (1 << bit);
            }
            obj = obj->link[isBitset];
        }
        return tempNum;
    }

    int getInverse(int num) { return INT_MAX ^ num; }

public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        for (int num : nums) {
            insert(num);
        }

        for (int num : nums) {
            int inverse = getInverse(num);
            int maxPossibleNum = search(inverse);
            maxXor = max(maxXor, (maxPossibleNum ^ num));
        }

        return maxXor;
    }
};