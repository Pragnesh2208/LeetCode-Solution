/******************** Optimal approach To find Frequency in limited range array****************/
/*******************Time complexity = O(N+M)***************************************************/
/*******************Space complexity = O(N+M)  ***********************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int , int>Map;
        for(int i=0 ;i<nums1.size() ;i++)
        {
            Map[nums1[i]]++;
        }
        for(int i=0; i<nums2.size() ;i++)
        {
            if(Map[nums2[i]]!=0)
            {
                ans.push_back(nums2[i]);
                Map[nums2[i]]--;
            }
        }
        return ans;
    }
};