/******************** Brute force approach To find Intersection points of 2 array****************/
/*******************Time complexity = O(NLOGN) + O(N * M)**************************************************/
/*******************Space complexity = O(N)  ***********************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        vector<int>ans;
        int last=-1;
       for(long long i=0;i<nums1.size();i++)
       {
           if(last==nums1[i])
               continue;
           for(long long j=0;j<nums2.size();j++)
           {
                
               if(nums1[i]==nums2[j])
               {   
                   last=nums1[i];
                   ans.push_back(nums1[i]);
                   break;
               }
               
           }
       }
        return ans;
        
    }
};


/******************** Optimal approach To find Frequency in limited range array****************/
/*******************Time complexity = O(N +M) **************************************************/
/*******************Space complexity = O(N)  ***********************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        vector<int>ans;
        for(auto i:nums1)
            s1.insert(i);
        for(long i=0;i<nums2.size();i++)
        {
            if(s1.find(nums2[i])!=s1.end())
            {
                ans.push_back(nums2[i]);
                s1.erase(s1.find(nums2[i]));
            }
        }
        return ans;
        
    }
};
