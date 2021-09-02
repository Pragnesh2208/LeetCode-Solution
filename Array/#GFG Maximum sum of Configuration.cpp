/*******************************Brute Force Approach to Find Maximum sum of configuration of array******************************/
/*******************************Time complexity = O(N^2) Big o of N square******************************************************/
/*******************************Space complexity = O(1)************************************************************************/

class Solution{
     public:
        int max_sum(int A[],int N)
        {
                int   Max=0;
        for(int i=0;i<N;i++)
        {
            int Config_sum=0;
            for(int j=0;j<N;j++)
            {
                Config_sum+=A[(j+i)%N]*j;
                
            }
            Max=max(Max,Config_sum);
        }
        return Max;

        }
}

/*******************************Optimal Approach to Find Maximum sum of configuration of array******************************/
/*******************************Time complexity = O(N)*********************************************************************/
/*******************************Space complexity = O(1)*******************************************************************/

class Solution{
     public:
            int max_sum(int A[],int N)
            {
            int sum=0 ,Config_sum=0;
            for(int i=0;i<N;i++)
            {
                sum+=A[i];
                Config_sum+=A[i]*i;
            }
            int Max=Config_sum;
            for(int i=0;i<N-1;i++)
            {
                Config_sum+=sum-N*A[N-1-i];
                Max=max(Max,Config_sum);
            }
            return Max;

            }
};

