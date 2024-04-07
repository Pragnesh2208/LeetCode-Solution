/********************************Optimal approach to Solve Using Greedy********/ 
/********************************Time Complexity  = O (  N  )*****************************/
/********************************Space Complexity  = O ( 1 )******************************/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int m = obstacles.size();
        int direction = 0;
        int ans = 0 ;
        vector<int> coverDistance(2 , 0);
        set<string>obstacleSet;
        vector<vector<int>>dir = { { 0 , 1} , { 1 , 0} , { 0 , -1} , { -1 , 0}};
        for(int i = 0 ; i < m ; i++) {
            obstacleSet.insert(to_string(obstacles[i][0]) + " " + to_string(obstacles[i][1]));
        }

        for(int i = 0 ; i < n ; i++) {
            if(commands[i] == -2) {
                direction--;
                if(direction < 0 ) {
                    direction = 3;
                }
            } else if(commands[i] == -1) {
                direction++;
                if(direction > 3) direction = 0;
            } else {
                int step = 0;
                while(step++ < commands[i] && obstacleSet.find(
                    to_string(coverDistance[0] + dir[direction][0]) +
                    " " +
                    to_string(coverDistance[1] + dir[direction][1])
                ) == obstacleSet.end()) {
                    coverDistance[0] += dir[direction][0];
                    coverDistance[1] += dir[direction][1];
                    
                }
            }
            ans = max(ans , (coverDistance[0] * coverDistance[0] )+ ( coverDistance[1] * coverDistance[1]));
        }
        return ans;
    }
};