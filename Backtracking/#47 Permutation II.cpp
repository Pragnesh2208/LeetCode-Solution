/********************************Optimal approach to Print all Unique Permutation*********/ 
/********************************Time Complexity  = O (  N * N!  )************************/
/********************************Here N to putting nums in result and N! for total permutations************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
    void getUniquePermutation( unordered_map<int,int>&freq , vector<vector<int>>&ans , vector<int>temp , int l) {
        if(temp.size() == l) {
            ans.push_back(temp);
            return;
        }

        for(pair<int,int>p : freq) {
            int number = p.first , count = p.second;
            if(count == 0) continue;
            temp.push_back(number);
            freq[number]--;
            getUniquePermutation( freq , ans , temp ,l );
            freq[number]++;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>temp;
        unordered_map<int,int>freq;
        for(int i = 0; i < n ; i++) {
            freq[nums[i]]++;
        }
        getUniquePermutation(freq , ans , temp , nums.size());
        return ans;
    }
};