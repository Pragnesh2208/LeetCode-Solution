/********************Optimal approach to Find Relative Rank************************************/
/*******************Time complexity = O(NLOGN) ************************************************/
/*******************Space complexity = O(N)  **************************************************/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        vector<string> st = {"Gold Medal" , "Silver Medal" , "Bronze Medal"};
      
        int pos = 1;
        int n = score.size();
        vector<string>ans(n);
        
        for(int i = 0 ; i < n ; i++ ) {
            pq.push(make_pair(score[i] , i));
        }
        
        while(!pq.empty()) {
        if(pos <= 3) {
            ans[pq.top().second] = st[pos++ - 1 ];
            
        }
            else {
                ans[pq.top().second] = to_string(pos++);
            }
            pq.pop();
        }
        return ans;
    }
};