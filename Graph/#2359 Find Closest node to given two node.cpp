/*****************************Optimal approach to find closest node to given two node******************/
/*****************************Time Complexity = O( V )*************************************************/
/*****************************Space Complexity = O( V )************************************************/
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1 , minDist = INT_MAX;
        int n = edges.size();
        vector<int>m1( n , -1) , m2 (n ,-1);
        
        for(int i = node1 , dist = 0 ; i!= -1 && m1[i] == -1 ; i = edges[i])
            m1[i] = dist++;
        for(int i = node2  , dist = 0 ; i!= -1 && m2[i] == -1 ; i = edges[i]){
            m2[i] = dist++;
            
            if(m1[i] != -1 && max(m1[i] , m2[i]) <= minDist){
                res = max(m1[i],m2[i]) == minDist ? min(i , res) : i;
                minDist = max(m1[i] , m2[i]);
            }

        }
        return res;
    }
};