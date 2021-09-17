/******************************Optimal approach to counting elements of two arrays***************/
/******************************Time complexity = O(M+N) *****************************************/
/*******************************Space complexity = O(M+N)****************************************/
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
    map<int ,int>Map;
    for(int i=0;i<n;i++)
    {
        Map[arr2[i]]++;
    }
   
    for(int i=0;i<m;i++)
    {
        if(Map[arr1[i]]==0)
        Map[arr1[i]]=0;
    }
     for(int i=1; i<Map.size();i++)
    { 
        Map[i]+=Map[i-1];
    }
       
    vector<int>ans;
    for(int i=0;i<m;i++)
    ans.push_back(Map[arr1[i]]);
    return ans;
    }
/******************************Optimal approach to counting elements of two arrays***************/
/******************************Time complexity = O(M*N LOGN) Big o of  M*N log N*****************/
/*******************************Space complexity = O(1)******************************************/
class Solution {
public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        sort(arr2,arr2+n);
        vector<int>ans;
        for(int i=0;i<m;i++){
        int low=0,high=n-1;
       int target=arr1[i];
       int count=0;
        while(low<=high)
        {
            int mid =low +(high -low)/2;
            if(arr2[mid]<=target)
            {count+=mid-low+1;
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        ans.push_back(count);
        }
        return ans;
    
    }
};