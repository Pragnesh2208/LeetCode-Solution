 /******************************Optimal approach to Find floor of elements in array***************/
/*******************************Time complexity = O(LOGN) Big o of log N**************************/
/*******************************Space complexity = O(1)*******************************************/
class Solution{
public:
int floor(int arr[] ,int N , int k){
int ans=-1;
    int low=0,high =N;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==K)
        {
        return mid;
        }
        else if(arr[mid] < K)
        {
            ans=mid;
            low=mid+1;}
        else
        high=mid-1;
    }
    return ans;
}
};

/******************************Optimal approach to Find floor of elements in array***************/
/*******************************Time complexity = O(LOGN) Big o of log N**************************/
/*******************************Space complexity = O(1)*******************************************/

class Solution{
  public:
 
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int left = 0 , right = n - 1;
        
        while(left <= right) {
            
            long long mid = left + (right - left) /2;
            
            if(v[mid]<=x)
                left = mid + 1;
            else
            right = mid -1;
        }
        return right == -1 ? -1 : left -1;
    }
};
