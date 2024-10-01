/**
 * Optimal approach to Count Xor pair with a ranges
 * Time Complexity = O(N)
 * Space Complexity  = O(N)
 */

struct Trie {
    Trie* link[2] = {NULL};
    int count = 0;
};
class Solution {
private:
    Trie* root;

    void insert(int num) {
        Trie* obj = root;
        for (int bit = 14; bit >= 0; bit--) {
            bool isBitset = (num & (1 << bit));
            if (obj->link[isBitset] == NULL) {
                Trie* newObj = new Trie();
                obj->link[isBitset] = newObj;
            }
            obj = obj->link[isBitset];
            obj->count++;
        }
    }

    int getCount(Trie * obj) {
        if(obj == NULL) return 0;
        return obj -> count;
    }
    int pairBelowNum(Trie* obj, int num, int limit, int bit) {

        if (!obj)
            return 0;
        if(bit <0) return obj -> count;

        bool setBitOfNum = (num & (1 << bit));
        bool setBitOfLimit = (limit & (1 << bit));

        if (setBitOfNum == 0) {
            if (setBitOfLimit == 0)
                return pairBelowNum(obj->link[0], num, limit, bit - 1);
            return getCount(obj->link[0]) +
                   pairBelowNum(obj->link[1], num, limit, bit - 1);
        } else{
            if(setBitOfLimit == 0) {
                return pairBelowNum(obj -> link[1] , num , limit , bit - 1);
            }
            return getCount(obj -> link[1]) + pairBelowNum(obj -> link[0] , num , limit, bit - 1);
        }
    }

public:
    Solution() { root = new Trie(); }

    int countPairs(vector<int>& nums, int low, int high) {
        int ans = 0;
        for (int num : nums) {
            ans += pairBelowNum(root, num, high, 14);
            ans -= pairBelowNum(root, num, low - 1, 14);
            insert(num);
        }
        return ans;
    }
};