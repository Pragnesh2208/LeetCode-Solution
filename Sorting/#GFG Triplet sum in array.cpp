/******************************optimal approach To Find Triplet sum in array*******************************/
/******************************Time complexity = O(N^2) big oh of N square**************************/
/******************************Space complexity = O(N)**********************************************/
class Solution {
public:
    bool find3Numbers(int a[], int n, int x)
    {
    sort(a,a+n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i==0 || a[i]!=a[i-1])
        {
            int left=i+1;
            int right=n-1;
            while(left < right)
            {
                if(a[i]+a[left]+a[right]==x)
                {
                    return true;  
                }
                else if(a[i]+a[left]+a[right]<x)
                {
                     while(a[left]==a[left+1] && left+1 < right)
                    left++;
                    left++;
                }
                else{
                     while(a[right]==a[right-1] && right-1 > left)
                    right--;
                    right--;
                }
            } 
        }
    }
        return false;
}
};