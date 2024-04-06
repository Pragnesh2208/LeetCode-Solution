/********************************Optimal approach to usign greedy + two pointer********/ 
/********************************Time Complexity  = O (NLogN)*****************************/
/********************************Space Complexity  = O (1)******************************/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int boat = 0;
        sort(people.begin() , people.end());
        int left = 0 , right = n - 1;

        while(left < right) {
            if(people[right] + people[left] <= limit) {
                boat++;
                right--;
                left++;
            } else {
                boat++;
                right--;
            }
        }

        if(left == right) boat++;

        return boat;
    }
};