/*******************************Optimal Approach to Find Max Index*************************************************************/
/*******************************Time complexity = O(N)*************************************************************************/
/*******************************Space complexity = O(N)************************************************************************/
class Solution{
    public:
            int maxIndexDiff(int A[], int n) 
                { 
                    int Min[n],maxdist=INT_MIN;
                    Min[0]=A[0];
                    for(int i=1;i<n;i++)
                    {
                        Min[i]=min(A[i],Min[i-1]);
                    }
                    int i=n-1,j=n-1;
                    while(i>=0 && j>=0)
                    {
                        if(A[j]>=Min[i])
                        {
                            maxdist=max(j-i , maxdist);
                            i--;
                        }
                        else
                        {
                            j--;
                        }
                    }
                    return maxdist;
                }
};

/*******************************Brute Force Approach to Find Max Index*************************************************************/
/*******************************Time complexity = O(N^2) Big o of N square********************************************************/
/*******************************Space complexity = O(1)**************************************************************************/

class Solution{
    public:
            int maxIndexDiff(int A[], int n) 
                { 
                    int maxdist=INT_MIN;
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(A[j]>=A[i])
                            maxdist=max(maxdist,j-i);
                        }
                    }
                }
};
