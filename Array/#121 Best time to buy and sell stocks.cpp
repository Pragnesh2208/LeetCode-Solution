/******************** Optimal approach To Buy and sell stock********************************/
/*******************Time complexity = O(N)**************************************************/
/*******************Space complexity = O(1)  ***********************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int profit=0;
        int Min=INT_MAX;
        for(int i=0;i<prices.size() ;i++)
        {
            if(prices[i] < Min)
                Min=prices[i];
            else 
                profit=max(prices[i]-Min ,profit);
        }
        return profit;
    }
};