/******************** Optimal approach To Rearrange array in O(1) space complexity************/
/*******************Time complexity = O(N)****************************************************/
/*******************Space complexity = O(1)***************************************************/
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long a[], int n) {
        // Your code here
        for(int i=0;i<n;i++)
        {
           a[i]=(a[i]%n)+(a[a[i]]%n)*n;
        }
        for(int i=0;i<n;i++)
        {
            a[i]=a[i]/n;
        }
        
    }
};