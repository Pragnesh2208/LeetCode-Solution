/********************************Optimal approach to get All Subsets********/ 
/********************************Time Complexity  = O (  (2 ^ N ) * K )************************/
/********************************Here K to putting temp in ans and N * K for average length  of every subset************/
/********************************Space Complexity  = O ( ( 2 ^ N ) * K)******************************/
/********************************here we will store 2 ^ N in answer that have average length of K***********************/ 
class Solution {

    private:
    void getSubset(int ind , vector<int> & temp , vector<vector<int>> &ans , vector<int> & arr )
    {
        int n = arr.size();
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
       ans.push_back(temp);
        for(int i = ind ; i < n ; i++){
        temp.push_back(arr[i]);
        getSubset(i + 1 , temp , ans , arr);
        temp.pop_back();
        }
        
    }
    public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        getSubset(0 , temp , ans , nums);
        return ans;
    }
};