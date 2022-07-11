/*****************************Optimal solution of Find Minimum number of vertices to reach all nodes******/
/****************************Time Complexity = O( V + E)**************************************************/
/***************************Space Complexity = O(N) as we are using  array vertices***********************/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vertices(n);
        for(int i = 0 ; i < n  ; i++) vertices[i] = i;
        for(int i = 0 ; i < edges.size() ;i++){
            int child = edges[i][1];
            vertices[child] =-1;
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++)
            if(vertices[i] != -1)
                ans.push_back(i);
        return ans;
    }
};