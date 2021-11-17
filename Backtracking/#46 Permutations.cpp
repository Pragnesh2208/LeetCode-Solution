/********************************Optimal approach to Print all Permutation*********/ 
/********************************Time Complexity  = O (  N * N!  )************************/
/********************************Here N for loop and N! for total permutations************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>>result;
        recursivePermute(nums , 0 , result);
        return result;
    }
    void recursivePermute(vector<int>&nums , int index , vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = index ; i <  nums.size() ; i++) {
         swap(nums[i] , nums[index]);
            recursivePermute(nums , index+1 , result);
            swap(nums[i] , nums[index]);
        }
    }
};