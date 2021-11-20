/********************************Optimal approach to Print all Permutation*********/ 
/********************************Time Complexity  = O (  N * N!  )************************/
/********************************Here N to putting nums in result and N! for total permutations************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
private:
    void getPermutation(int ind , vector<vector<int>> &ans , vector<int> &arr) {
         int N = arr.size();
        if(ind == N){
            ans.push_back(arr);
            return;
        }
      
        for(int currIndex = ind ; currIndex < N ; currIndex++){
             if(currIndex > ind && arr[currIndex] == arr[currIndex - 1])
                 continue;
            swap(arr[currIndex] , arr[ind]);
            getPermutation(ind + 1 , ans , arr );
            swap(arr[currIndex] , arr [ ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        getPermutation(0 ,ans , nums);
        return ans;
    }
};