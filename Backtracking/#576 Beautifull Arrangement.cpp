/************************************Optimal solution to Generating Beautiful Arrangement********************************/
/************************************Time Complexity is O( N!) ****************************************************/
/************************************where N! is number of Permutation we are generating***************/
/************************************Space Complexity is O( N  )*****************************************************/
class Solution {
public:
    void getCombination(int n , vector<int> &nums, int &result) {
        if(n == 0)
        {
            result += 1;
            return;
        }
        for(int i = n ; i> 0 ; i-- ) {
            swap(nums[i] , nums[n]);
            if(nums[n] % n== 0 ||n % nums[n] == 0)
                getCombination(n - 1 , nums , result);
            swap(nums[i] , nums[n]);
        }
    }
    int countArrangement(int n) {
       vector<int>nums(n+1 , 0);
        for(int i = 1 ; i <= n ; i++ ) 
            nums[i] = i;
        int result =0 ;
    
        getCombination( n , nums ,result);
        return result;
    }
};