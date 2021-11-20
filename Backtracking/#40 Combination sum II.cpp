/********************************Optimal approach to find Combination sum II********/ 
/********************************Time Complexity  = O ( 2 ^ N )*****************************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
private:
    void getCombination(int ind , vector<int>&temp , int target , vector<vector<int>>&ans , vector<int>&candidates) {
    
        if(target == 0) {
            ans.push_back(temp);
             return;
            }
       int  n = candidates.size();
        for(int i = ind; i < n ; i++) {
            int prevIndex = i-1;
            int currIndex = i;
            
            if( i > ind  && candidates[currIndex] == candidates[prevIndex])
                continue;
            if(candidates[i]  > target)
                break;
            temp.push_back(candidates[currIndex] );
            getCombination( currIndex + 1 , temp , target - candidates[currIndex]  , ans , candidates);
             temp.pop_back();
        }
            
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin() , candidates.end());
        getCombination(0 , temp  , target , ans , candidates);
        return ans;
    }
};