/*************************Brute Force approach to find Subarray sum equals k in array********************/
/*************************Time complexity = O(N^2) Big o of N Square************************************/
/**************************Space complexity = O(1)*****************************************************/
class Solution {
    public:
     int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum=0;
            for (int end = start; end < nums.size(); end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}

/*************************Optimal approach to find Subarray sum equals k in array********************/
/*************************Time complexity = O(N)*****************************************************/
/**************************Space complexity = O(N)***************************************************/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        int sum=0;
        unordered_map<int , int>prevSum;
        for(int i=0;i<n;i++)
        {
             sum+=nums[i];
            if(sum==k)
                cnt++;
            if(prevSum.find(sum-k)!=prevSum.end())
                cnt+=prevSum[sum-k];
            prevSum[sum]++;
        }
        return cnt;
        
        
    }
};


