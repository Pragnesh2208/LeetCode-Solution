/********************Optimal approach to Remove Stones to Minimize the Total*******************/
/*******************Time complexity = O( (N+K) LOGN) ************************************************/
/*******************Space complexity = O(N)  **************************************************/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin() , piles.end());
        int res = 0;
        for(auto i : piles) {
            res += i;
        }
        while(k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x - floor(x/2));
            res -=  floor(x/2);
        }
        
        return res;
    }
};