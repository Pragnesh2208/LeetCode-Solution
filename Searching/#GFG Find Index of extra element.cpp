 /***************************Brute Force approach To Find Index of extra number****************************/
/****************************Time complexity = O(N)********************************************************/
/****************************Space complexity = O(1)*******************************************************/
class Solution{
public:
    int findExtra(int a[], int b[], int n) {
     for(int i=0;i<n;i++)
     if(a[i]!=b[i])
     return i;
     return -1;
    }
};
/****************************Brute Force approach To Find Index of extra number****************************/
/****************************Time complexity = O(LOGN)Big O of Log N***************************************/
/****************************Space complexity = O(1)*******************************************************/
class Solution{
 public:
    int findExtra(int a[], int b[], int n) {
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((a[mid]!=b[mid] && a[mid-1]==b[mid-1]) || (mid==0 && a[mid]!=b[mid]))
        return mid;
        else if(a[mid]!=b[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
    }
};