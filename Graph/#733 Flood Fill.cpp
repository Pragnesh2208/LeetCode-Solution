/*****************************Optimal solution for Flood Fill*************************/
/****************************Time Complexity = O( V + E)**************************************/
/***************************Space Complexity = O(V + E) as we are using visit*************/

class Solution {
    void dfs(int sr , int sc , vector<vector<int>>&image , vector<vector<bool>>&visit , int &color , int &row , int &col , int &val) {
        if(sr < 0 || sr == row || sc < 0 || sc == col  || visit[sr][sc] == true || image[sr][sc] != val)
            return;
        visit[sr][sc] = true;
        dfs(sr + 1 , sc , image , visit , color , row , col , image[sr][sc]);
        dfs(sr , sc - 1 , image , visit , color , row , col , image[sr][sc]);
        dfs(sr - 1 , sc , image , visit , color , row , col , image[sr][sc]);
        dfs(sr , sc + 1 , image , visit , color , row , col , image[sr][sc]);
                image[sr][sc] = color;

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>>visit(row , vector<bool>(col , false));
        
        dfs(sr , sc , image , visit , color , row, col , image[sr][sc]);
        
        return image;
    }
};