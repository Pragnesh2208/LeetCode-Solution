/********************Optimal approach To Merge sorted array*******************************/
/********************Time complexity = O(N +M)********************************************************/
/*******************Space complexity = O(1)*******************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=m-1 ,j=n-1  , l=m+n-1;
        while( i >= 0 && j>=0)
        {
            if(nums1[i] >=nums2[j])
            {
                nums1[l--]=nums1[i--];
                
            }
            else {
                    nums1[l--]=nums2[j--];
            }
        }
        while(j >= 0)
            nums1[l--]=nums2[j--];
        
    }
};