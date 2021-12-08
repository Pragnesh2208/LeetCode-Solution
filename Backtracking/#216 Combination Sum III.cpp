/********************************Optimal approach to Combination Sum ****************************************/ 
/**************************************Time Complexity O((2^t)*k)*********************************************/
/*Let's say if there are n number so we will have 2^n combination by pick and non-pick as we did in problem #1863 Sum of all subset XOR Total , but here we will have total x combination of length k and we will also have y combination whose sum will not match to target  ,so we will have total combination t = x + y 
so our Total time complexity = O( (2 ^ t ) * k)**************************************************************************************************/
/********************************Space Complexity  = O ( k * x )******************************/
/*we will have x number of combination , so we will have x complexity for recursion and it  for length k complexity for storing in temp 
so our total Space complexity = O (k * x)****************************************************************************************************/
class Solution {
    private:
    void getCombination(int ind , int k ,int n , vector<vector<int>> &ans , vector<int> &temp) {
        if(ind == 10 || k == 0) {
            if(k == 0 && n == 0 )
            ans.push_back(temp);
            return;
        }
        if(ind <= n ) {
           
            temp.push_back(ind);
            getCombination(ind +1 , k - 1  , n - ind , ans , temp);
            temp.pop_back();
            }
       
        getCombination(ind+1  , k , n , ans , temp );
    }
    public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>> ans;
        getCombination(1,k , n , ans , temp);
        return ans;
    }
};