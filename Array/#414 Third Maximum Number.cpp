/******************** Optimal approach To find Third Maximum Number of  array***********************/
/*******************Time complexity = O(N) ********************************************************/
/*******************Space complexity = O(1)*********************************************************/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
      
            long long Max1=-2147483649,Max2=-2147483649,Max3=-2147483649;
        for(auto i :nums)
        {     
            if( i>Max1)
            {
                Max3=Max2;
                Max2=Max1;
                Max1=i;
            }
            else if( i > Max2 && i <Max1)
            {
                Max3=Max2;
                Max2=i;
            }
            else if( i >Max3 && i <Max2)
                Max3=i;
        }
        if(Max3!=-2147483649)
            return Max3;
        return Max1;
     
        
    }
};