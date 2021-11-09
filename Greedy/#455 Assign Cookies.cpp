/********************************Optimal approach to Assign Cookies********************************/ 
/********************************Time Complexity  = O (  N LOG N  + M LOG M) ************************************************/
/********************************Space Complexity  = O ( 1 ) ***********************************************/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0 , j = 0 , n = g.size() , m = s.size() , ans = 0;
        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                ans++;
                i++;
                j++;
            }
            else if( g[i] > s[j])  {
                j++;
            }
            
        }
        return ans;
    }
};