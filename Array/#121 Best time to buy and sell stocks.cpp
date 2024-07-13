/******************** Optimal approach To Buy and sell stock********************************/
/*******************Time complexity = O(N)**************************************************/
/*******************Space complexity = O(1)  ***********************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int holding =  prices[0];
        for(int ind = 1 ; ind < n ;ind++) {
            if(prices[ind] > holding) {
                profit = max(profit , prices[ind] - holding);
            } else holding = prices[ind];
        }
        return profit;
    }
};