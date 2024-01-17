class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int>bucket;
        int n = cards.size() , ans = INT_MAX;

        for(int i = 0 , j = 0 ; i < n ; i++) {
            bucket[cards[i]]++;
            
            while(bucket[cards[i]] == 2) {
                ans = min(ans , i -j + 1);
                bucket[cards[j++]]--;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};