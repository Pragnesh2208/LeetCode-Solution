/*******************************Brute Force Approach to Find Minimum Distance between two number***********************************/
/*******************************Time complexity = O(N^2) Big O of N Square*********************************************************/
/*******************************Space complexity = O(1)****************************************************************************/
class solution
{
    public:
    int minDist(int a[], int n, int x, int y) {
        int minDist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x||a[i]==y) {
                for(int j=i+1;j<n;j++){
                    if(a[j]==x || a[j]==y && a[i]!=a[j])
                    {
                        minDist=min(minDist,j-i);
                    }
                }
            }
        }
        if(minDist!=INT_MAX)
        return minDist;
        else
        return -1;
    }
};
/*******************************Optimal Approach to Find Minimum Distance between two number***********************************/
/*******************************Time complexity = O(N)*************************************************************************/
/*******************************Space complexity = O(1)************************************************************************/

class Solution {
public:
    int minDist(int a[], int n, int x, int y) {
        int j,prev;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x||a[i]==y)
            {
                prev=i;
                j=i;
                break;
            }
        }
        int minDist=INT_MAX ;
        for(int i=j+1;i<n;i++)
        {
            if(a[i]==x||a[i]==y)
            {
                if(a[i]!=a[prev] && minDist >( i-prev))
                {
                    minDist=i-prev;
                }
                prev=i;
            }
        }
        if(minDist!=INT_MAX)
        return minDist;
        else
        return -1;
    }
};


/*******************************Optimal Approach to Find Minimum Distance between two number***********************************/
/*******************************Time complexity = O(N)*************************************************************************/
/*******************************Space complexity = O(1)************************************************************************/

class Solution {
public:
    int minDist(int a[], int n, int x, int y) {
        int xi = -1, ji =-1 , minDist = INT_MAX;
        for(int i=0;i<n;i++)
        {
           if(a[i] == x) xi = i;
           else if(a[i] == y) yi = i;
           if(xi != -1 && yi != -1)
           minDist = min(abs(xi - yi) , minDist);
        }
       
        if(minDist!=INT_MAX)
        return minDist;
        else
        return -1;
    }
};

