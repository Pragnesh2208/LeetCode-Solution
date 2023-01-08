/************************Optimal SOlution to Find Kth Largest Element*************************/
/************************Time Complexity = O(N * LogN)**************************************************/
/************************Space Complexity = O(1)*************************************************/
class Solution {
   static bool cmp(string a , string b){
        // return stoi(a) < stoi(b);
        if(a.length() > b.length() ) return true;
        // cout<<a<<" "<<b<<" "; 
        if(a.length() == b.length()) {
            return a > b;
        }
        else return false;
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin() , nums.end() , cmp);
       return nums[k -1];
    }
};