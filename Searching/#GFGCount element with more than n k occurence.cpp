 /********************Brute Force approach To Find number of occurrence More than n/k*******************************/
/********************Time complexity = O(NLOGN) Big o of N log N********************************************************/
/*******************Space complexity = O(1)*******************************************************/
 class Solution {
 public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        sort(arr ,arr+n);
        int count=0 , occur =n/k , ans=0;
        for(int i=0;i<n-1;i++)
        {
            while(arr[i]==arr[i+1])
           { count++;
               i++;
           }
            count++;
            if(count > occur)
            ans++;
           count=0;
        }
        return ans;
    }
};
 /***************************Brute Force approach To Find number of occurrence More than n/k***************/
/****************************Time complexity = O(N)********************************************************/
/****************************Space complexity = O(N)*******************************************************/
class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        map<int,int>Table;
        int count=0;
        for(int i=0;i<n;i++)
        {
            Table[arr[i]]+=1;
        }
        for(int i =0;i<Table.size();i++)
        {
            if( Table[i]> n/k)
            count++;
        }
    return count;        
    }
};
