/********************************Optimal approach to get All unique Subsets*****************************************/ 
/********************************Time Complexity  = O (  (2 ^ N ) * K )************************/
/********************************Here K to putting temp in ans and N * K for average length  of every subset************/
/********************************Space Complexity  = O (N)******************************/
class Solution {
    private :
    void getCombination(int ind , vector<int> & temp , vector<vector<int>> & ans , vector<int> & arr) {
        int n =arr.size();
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        for(int i = ind ; i < n ; i++ ){
            if( i > ind && arr[i] == arr[i-1]) 
                continue;
            temp.push_back(arr[i]);
            getCombination(i+1 , temp ,ans , arr);
            temp.pop_back();
        }
    } 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        getCombination(0 , temp , ans , nums);
        return ans;
    }
};