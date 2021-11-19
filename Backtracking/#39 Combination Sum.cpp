/********************************Optimal approach to Combination Sum ****************************************/ 
/**************************************Time Complexity O((2^t)*k)*********************************************/
/*Let's say if there are n number so we will have 2^n combination by pick and non-pick as we did in problem #1863 Sum of all subset XOR Total , but here we can use single number for more than once so we will have total x combination of length k and we will also have y combination whose sum will not match to target  ,so we will have total combination t = x + y 
so our Total time complexity = O( (2 ^ t ) * k)**************************************************************************************************/
/********************************Space Complexity  = O ( k * x )******************************/
/*we will have x number of combination , so we will have x complexity for recursion and it  for length k complexity for storing in temp 
so our total Space complexity = O (k * x)****************************************************************************************************/

class Solution {
public:
    void combination (int index , int target , vector<vector<int>>&ans , vector<int> &candidates , vector<int>&temp) {
        if(index == candidates.size()) {
            if(target == 0)
                ans.push_back(temp);//for copying k number in ans will take time complexity O(k)
            return ;
        }
        if(candidates[index] <= target) {
            temp.push_back(candidates[index]);
            combination(index , target - candidates[index] , ans , candidates , temp);
            temp.pop_back();
        }
        combination(index+1 , target , ans, candidates , temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        combination( 0 , target , ans , candidates , temp);
        return ans;
    }
};