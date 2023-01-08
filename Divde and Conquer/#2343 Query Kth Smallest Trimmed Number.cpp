/************************Brute Force Approach to find Query Kth Smallest Trimmed Number*************************/
/************************Time Complexity = O(M*N)**************************************************/
/************************Space Complexity = O(N)*************************************************/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;

        for(int i = 0 ; i < m ;i++) {
            vector<pair<string , int>>temp;
           
            for(int j = 0 ; j < n ; j++)  {
                temp.push_back({nums[j].substr(nums[j].length() - queries[i][1]) , j});
            }   

            sort(temp.begin() , temp.end());
            ans.push_back(temp[queries[i][0] - 1].second);
        }
 
        return ans;
    }
};

/************************Optimal Approach to find Query Kth Smallest Trimmed Number*************************/
/************************Time Complexity = O(N^2 * Length )**************************************************/
/************************Space Complexity = O(N * Length)*************************************************/
/*************************Here Length  = nums[0].length()*************************************************/

class Solution {
    private:
    void bucket_sort(vector<string>&nums , vector<vector<pair<string,int>>> &mp , int index) {
        int n = nums.size();
        vector<pair<string ,int>> temp;
        for(int i =0 ; i <n ; i++) {
            string str = nums[i].substr(index);
          temp.push_back({str, i});
        }
        sort(temp.begin() , temp.end());
        mp.push_back(temp);
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<vector<pair<string,int>>> mp;
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;
        int length = nums[0].length() - 1;
        for(int i = length; i >= 0 ; i--) bucket_sort(nums , mp ,i );

        for(int i = 0 ; i < m ; i++) {
            int k = queries[i][0];
            int index = queries[i][1];
            ans.push_back(mp[index - 1][k - 1].second);
        }
        return ans;
    }
};