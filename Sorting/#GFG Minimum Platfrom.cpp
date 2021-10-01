/******************************Optimal approach to find Minimum platform******************/
/******************************Time complexity = O(NLogN)***********************************************/
/******************************Space complexity = O(1)**********************************************/
 class Solution {
 int findPlatform(int a[], int d[], int n)
    {
        int count=1;
    	sort(a,a+n);
    	sort(d,d+n);
    int j=0;
   
   for(int i=1;i<n;i++)
   {
       if(a[i]<=d[j])
       count++;
       else
       j++;
   }
    	return count;
    }
};
