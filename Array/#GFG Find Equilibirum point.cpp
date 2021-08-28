/******************** Brute force approach To find Equilibirum point in array ****************/
/*******************Time complexity = O(n^2) big oh of n square *****************************/
/*******************Space complexity = O(1)  ***********************************************/

class solution{
             public:
    int equilibriumPoint(long long a[], int n) {
    
        if(n==1)
             return 1;
        
        for(long long i=0;i<n;i++)
         { 
             long long sum=0;
             for(long long j=i+1;j<n;j++)
             sum+=a[j];
             for(long long j=0;j<i;j++)
             sum-=a[j];
             if(sum==0)
             return i+1;
         }
        return -1;
    }

};
/******************** Optimal force approach To find Equilibirum point in array ****************/
/*******************Time complexity = O(n) big oh of n square *****************************/
/*******************Space complexity = O(1) ***************************************************/
 class Solution {
 public:
    int equilibriumPoint(long long a[], int n) {
         if(n==1)
            return 1;
        long long sum=0;
         for(long long i=0;i<n;i++)
             sum+=a[i];
            
             long long l=0;
         for(long long i=1;i<n;i++)
         {
             l+=a[i-1];
             sum-=a[i-1];
             if(sum-a[i]==l)
             return i+1;
             
         }
         return -1;
    }

};