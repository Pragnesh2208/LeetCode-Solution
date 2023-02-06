/****************Find Maximum sum of non-adjacent element using Space Optimization*******************/
/****************Time Complexity = O(n)**************************************************************/
/****************Space Complexity = O(N)*************************************************************/
//Note : code is same as Maximum-sum-of-non-adjacent-element
#include <bits/stdc++.h> 
using namespace std;

long long int spaceOptimization(vector<long long int>&nums ) {  
   long long int prev1 = nums[0] , prev2;
    long long int n = nums.size();

    for(long long int  i = 1 ; i < n ; i++) {
        if(i == 1) {
           prev2 = prev1;
            prev1 = max(prev1 , nums[i]);
        }
        else {
            long long int temp = prev1;
            prev1 = max(prev1 , nums[i] + prev2);
            prev2 = temp;
        }
         
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
 long long int n = valueInHouse.size();
 if(n == 1) return valueInHouse[0];
 vector<long long int>t1  , t2;
 for(long long int i = 0 ; i < n ; i++) {
     if(i != n -1) t1.push_back(valueInHouse[i]);
     if(i != 0 ) t2.push_back(valueInHouse[i]);
 }   
 return max(spaceOptimization(t1) , spaceOptimization(t2));
}