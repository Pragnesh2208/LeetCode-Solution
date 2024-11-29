/**
 * Optimal Approach to Solve Cheapest Flights Within k stops
 * Time Complexity = O(m * log(n * k))
 * where m is total edge , n is vertices and k is stop limit.
 * Space Complexity = O(n * k);
 */
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        // Steps
        // 0. Create Graph
        // 1. create a dist array
        // 2. use Dijakstra
        vector<vector<pair<int,int>>> graph(n);
        for(vector<int>&flight : flights) {
            int src = flight[0];
            int dest = flight[1];
            int price = flight[2];
            graph[src].push_back({dest , price});
        }
        
        vector<int>dist(n ,  INT_MAX);
        set<pair<int,pair<int,int>>>pq;
        dist[src] = 0;
        pq.insert({0 , {src , 0}});
   
        while(!pq.empty()) {
            int flightCharge = pq.begin() -> second.second;
            int flightSrc = pq.begin() -> second.first;
            int totalStops = pq.begin() -> first;
            dist[flightSrc] = min(dist[flightSrc] , flightCharge);
            // cout<<flightCharge << " " <<flightSrc <<" "<<totalStops <<endl; 
            pq.erase(pq.begin());
            if (totalStops > k) continue;
            for(const pair<int,int> childFlight : graph[flightSrc]) {
                int desti = childFlight.first;
                int price = childFlight.second;
                int newCost = flightCharge + price;
                
                if(dist[desti] > newCost ) {
                    pq.insert({ totalStops + 1 , {desti , newCost}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};