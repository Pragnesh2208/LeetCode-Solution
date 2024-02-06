/*
Brute Force Approach
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin() , people.end()  , cmp);
        int n = people.size();

        vector<vector<int>> ans(n , vector<int>(2,-1));

        for(int i = 0 ; i < n ; i++) {
            int count = 0;
            cout<<people[i][0]<<" "<<people[i][1]<<endl;
            for(int j = 0 ; j < n  ; j++) {
                if(count == people[i][1] && ans[j][0] == -1) {
                    ans[j] = people[i];
                    break;
                }
                if(ans[j][0] == -1 ) count++;
            }
        }

        return ans;
    }

     static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};