/********************Brute Force  approach To Find median of two sorted array***************/
/*******************Time complexity = O(NLOGN)Big o of N log N******************************/
/*******************Space complexity = O(N)  ***********************************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin() ,nums2.end());
        sort(nums1.begin() , nums1.end());
        int size=nums1.size();
        cout<<size<<endl;
        if(size%2!=0)
            return (doublAe)nums1[size/2];
        else
            return (double)(nums1[size/2]+nums1[size/2 -1])/2;
        return 1;
        
        
    }
};
/********************Optimal approach To Find median of two sorted array***************/
/*******************Time complexity = O(min(logN1,logN2))******************************/
/*******************Space complexity = O(1)********************************************/

class Solution {
public:
    double median(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size();
        int N2=nums2.size();
        if(N1==0 && N2==0)
            return 0.0;
       else if(N1==0)
        {
            if(N2%2==0)
                return (double)(nums2[N2/2] +nums2[N2/2 -1])/2;
            else
                return (double)nums2[N2/2];
        }
        else if(N2==0)
        {
            if(N1%2==0)
                return (double)(nums1[N1/2] +nums1[N1/2 -1])/2;
            else
                return (double)nums1[N1/2];
        }
        
        else{
        int left=0 ,right=N1;
        while(left<=right)
        {
            int median1=left+(right-left)/2;
            int median2=(N1+N2+1)/2 - median1;
            
            int left1=(median1==0)?INT_MIN:nums1[median1-1];
            int right1=(median1==N1)?INT_MAX:nums1[median1];
            int left2=(median2==0)?INT_MIN:nums2[median2-1];
            int right2=(median2==N2)?INT_MAX:nums2[median2];
            
           if((left1<=right2) &&(left2<=right1)) {
                if((N1+N2) % 2==0)
                return double(max(left1,left2)+min(right1,right2))/2;
                else
                    return double(max(left1,left2));      
            }   
            else if(left1 > right2)
                right=median1-1;
            else
                left=median1+1;
        }
        return 0.0;
        
    }
    }
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         double ans;
         int n=nums1.size();
         int m=nums2.size();
         if(n>m)
           ans=  median(nums2,nums1);
             else
               ans=  median(nums1,nums2);
         return ans;
     
    }
};