/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (NLogN) ***********************************/
/********************************Space Complexity  = O (N) **********************************/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int , int>> mp;
        for(int i = 0 ; i < n ; i++) {
            mp.push_back({nums2[i] , i});
        }
        
        sort(mp.begin() , mp.end());
        sort(nums1.begin() , nums1.end());

        int i = 0 , j = 0 , k = n - 1;

        vector<int>nums3( n , 0);
        while(i < n && j < n ) {
            if(mp[i].first >= nums1[j]) {
                nums3[mp[k].second] = nums1[j];
                j++;
                k--;
            } else {
                int index = mp[i].second;
                nums3[index] = nums1[j];
                i++;
                j++;
            }   
        }

        return nums3;
    }
};