 /******************************optimal approach To Count possible number triangle in array*********/
/******************************Time complexity = O(N^2) big oh of N square**************************/
/******************************Space complexity = O(1)**********************************************/
 class Solution {
 public:

    int findNumberOfTriangles(int arr[], int n){
        sort(arr,arr+n);
        int ans=0;
        for(int i=n-1;i>=2;i--)
        {
            int left=0;
            int right=i-1;
            while(left<right)
            {
                if(arr[left] +arr[right] > arr[i])
                {
                    ans+=right-left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }

};