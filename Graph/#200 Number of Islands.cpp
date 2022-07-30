
/*****************************Optimal approach to find the Number of Islands***************************/
/*****************************Time Complexity = O( V + E)**********************************************/
/*****************************Space Complexity = O(V + E ) as we are using visit array and stack space*/
class Solution {
    private:
    bool isValid(int i  , int j, int &row , int &col , vector<vector<char>> & grid , vector<vector<bool>> &visit ){
        
if(i >= 0  &&  i < col &&  j >= 0 && j < row && grid[i][j] == '1' && visit[i][j] == false)
               return true;
        else return false;
    }
    
    void dfs(int i  , int j, int &row , int &col , vector<vector<char>> & grid , vector<vector<bool>> &visit) {
        
     if(isValid(i , j , row , col , grid , visit))
        {
          
        visit[i][j] = true;
            
            for(int way = -1 ; way<=1 ; way += 2){
                dfs(i + way , j , row , col , grid , visit);
                dfs(i , j + way , row , col , grid , visit);
            }

        }        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid[0].size();
        int col = grid.size();
        int count =  0;
        vector<vector<bool>> visit (col , vector<bool>(row , false));
        for(int i = 0 ; i < col  ; i++ ){
            for(int j = 0 ; j<row ; j++){
                
                if(visit[i][j] == false && grid[i][j] == '1'){
                    dfs(i , j ,row , col, grid , visit);
                    count++;
                }
            }
        }   
        return count;
       
        
    }
};