/*Optimal Solution
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int remaining_fuel  = 0, total_fuel = 0 , ans = 0;

        for(int i = 0 ; i < n ; i++) {
            remaining_fuel += (gas[i] - cost[i]);
            total_fuel += (gas[i] - cost[i]);
            if(remaining_fuel < 0 ) {
                remaining_fuel = 0;
                ans = (i + 1) % n ;
            } 
        }

        return total_fuel < 0 ? -1 : ans;
    }
};