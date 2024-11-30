/**
 * Optimal Approach to solve minimum multiplications to reach end
 * Time Complexity = O( log(1e5) * 1e5 * len)
 * Space Complexity = O(1e5 * len)
 */

class Solution {
    private :
    int maxLimit = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        vector<int>dist(maxLimit , INT_MAX);
        set<pair<int,int>>pq;
        int len = arr.size();
        dist[start] = 0;
        pq.insert({1 , start});
        
        while(!pq.empty()) {
            int cost = pq.begin() -> first;
            int newStart = pq.begin() -> second;
            dist[newStart] = min(dist[newStart] , cost);
            
            pq.erase(pq.begin());
            if(cost > dist[end]) continue;
            for(int ind = 0 ; ind < len ; ind++) {
                int newDest = (arr[ind] * newStart) % maxLimit;
                int newCost = cost + 1;
                if(dist[newDest] > newCost) {
                    pq.insert({newCost , newDest});
                }
            }
        }
        
        return dist[end] == INT_MAX ? -1 : dist[end] - 1 ;
    }
    
};